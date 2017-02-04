#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// structure of tree node

struct tNode{
    struct tNode* left;
    int val;
    struct tNode* right;  
};

// Create a tree  node
struct tNode * newtNode(int val) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = val;
	x->right = NULL;
	return x;
}


// Calculate maximum of two integer values 


int maxOf(int i, int j) {
    if(i>=j) return i;
    return j;
}

// Calculate height of tree


int height(struct tNode *root) {
    if(root == NULL) return 0;
    return (maxOf(height(root->left), height(root->right)) + 1);
}


// structure of q data

struct cus_qData {
    struct tNode *tNode_ptr;
    int tNode_level;
};



// Structure of queue Node
struct qNode {
	struct cus_qData qData;
	struct qNode *next;
};

// create new queue node

struct qNode * newqNode(struct cus_qData qData) {
	struct qNode *x = (struct qNode *)malloc(sizeof(struct qNode));
	x->qData = qData;
	x->next = NULL;
	return x;
}


// Enqueue 

enqueue(struct cus_qData qData, struct qNode **frontref, struct qNode **rearref) {
	// if inserting as first node in queue
	if((*frontref) == NULL) {
		*rearref = newqNode(qData);
		*frontref = *rearref;
	}
	else {
		struct qNode *oldrear = *rearref;
		*rearref =newqNode(qData);
		oldrear->next = *rearref;
	}
}


// Dequeue - returns pointer to tree node
struct cus_qData dequeue(struct qNode **frontref, struct qNode **rearref) {
	// get the value of front node
	struct cus_qData qData = (*frontref)->qData;
	// remove the front member from the queue
	(*frontref) = (*frontref)->next;
	// Check if no member in queue...if thats the case, there there wouldnt be any member // at the back of te queue as well
	if((*frontref) == NULL) (*rearref) = NULL;
	// return the stored value pointed earlier by front
	return qData;
}

// check if queue empty
bool isEmpty(struct qNode **frontref) {
   // printf("frontref = %d\n",(*frontref)->tptr->val);
	return((*frontref) == NULL);
}


// Done with queue



// start with stack structure and functions


// structure of stack node


struct cus_sData {
    int tNode_val;
    int tNode_level;
};

struct sNode {
    struct cus_sData sData;
    struct sNode *next;
};

// create new stack node

struct sNode * newsNode(struct cus_sData sData) {
    struct sNode *x = (struct sNode *)malloc(sizeof(struct sNode));
    x->sData = sData;
    x->next = NULL;
    return x;
}

// push

push(struct cus_sData sData, struct sNode **topref) {
    struct sNode *x = newsNode(sData);
    x->next = *topref;
    *topref = x;
    x = NULL;
    free(x);
}

// pop

struct cus_sData pop(struct sNode **topref) {
    struct cus_sData sData = (*topref)->sData;
    (*topref) = (*topref)->next;
    return sData;
}

// check for empty stack 

bool issEmpty(struct sNode **topref) {
    return((*topref) == NULL);
}

// modified bfs

bfs_mod(struct tNode *root) {
    struct tNode *current = root;
    //Declare front and rear for queue and top for stack
    struct qNode *front = NULL, *rear = NULL;
    struct sNode *top = NULL;
	// We would also need temporary variables for queue and stack data
	struct cus_qData qData;
	struct cus_sData sData;
	// We would also need temporary variables for tNode value and level
	int tNode_val;
	int tNode_level = 0;
	// We would also need temporary variable for pointing to tree node
	struct tNode *tNode_ptr = NULL;
	
	// Enqueue current tNode value and level
	qData.tNode_ptr = current;
	qData.tNode_level = tNode_level;
	enqueue(qData, &front, &rear);
	
	while(!isEmpty(&front)) {
	    // Dequeue Q Data
		qData = dequeue(&front, &rear);
		
		// Break Q data into tNode pointer and tNode level
	    tNode_ptr = qData.tNode_ptr;
        tNode_level = qData.tNode_level;
	
		// prepare stack data and push
		sData.tNode_val = tNode_ptr->val;
		sData.tNode_level = tNode_level;
		push(sData, &top);
		
		// Enqueue right and left
		if(tNode_ptr->right != NULL) {
			// Prepare q Data
			qData.tNode_ptr = tNode_ptr->right;
			qData.tNode_level = tNode_level + 1;
			enqueue(qData, &front, &rear);
		}
		
		if(tNode_ptr->left != NULL) {
			// Prepare q Data
			qData.tNode_ptr = tNode_ptr->left;
			qData.tNode_level = tNode_level + 1;
			enqueue(qData, &front, &rear);
		}
	} // End While
	
	// Start popping from stack till empty
	
	// declare variables to store current and previous levels
	int curr_level = height(root) - 1;
	int prev_level = curr_level;
	//printf("Prev_level = %d", prev_level);
	while(!issEmpty(&top)) {
		sData = pop(&top);
		
		// Break stack data into primitive
		tNode_val = sData.tNode_val;
		curr_level = sData.tNode_level;
		if(curr_level < prev_level) {
			// We need to move to next line
			printf("\n");
			// Set prev_level to curr_level
			prev_level = curr_level;
		}
		// Print tNode value
		printf("%d ", tNode_val);
	}
}

reverseOrderPerLine(struct tNode *root) {
    bfs_mod(root);
}


// client

int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	root->right->left = newtNode(6);
	root->right->right = newtNode(7);
	// pass the tree for doing level order traversal
	reverseOrderPerLine(root);
	getch();
}
