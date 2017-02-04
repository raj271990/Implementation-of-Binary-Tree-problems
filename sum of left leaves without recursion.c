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




// Queue structure ans related functions



// structure of q data

struct cus_qData {
    struct tNode *tNode_ptr;
    bool is_lc_of_Parent;
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



// bfs modified
bfs_mod(struct tNode *current) {
    int sum_left_leaves = 0;
    bool is_lc_of_Parent = false;
    struct cus_qData qData;
    struct qNode *front = NULL, *rear = NULL;
    
    // Prepare qData
    qData.tNode_ptr = current;
    qData.is_lc_of_Parent = false;
    enqueue(qData, &front, &rear);
    
    while(!isEmpty(&front)) {
        qData = dequeue(&front, &rear);
        current = qData.tNode_ptr;
        is_lc_of_Parent = qData.is_lc_of_Parent;
        
        // Check if dequed node is left leaf
        if(current->left == NULL && current->right == NULL && is_lc_of_Parent) {
             sum_left_leaves = sum_left_leaves + current->val;
        }
        
        // Enqueue left and right child o current tree node
        if(current->left != NULL) {
            qData.tNode_ptr = current->left;
            qData.is_lc_of_Parent = true;
            enqueue(qData, &front, &rear);
        }
        
        if(current->right != NULL) {
            qData.tNode_ptr = current->right;
            qData.is_lc_of_Parent = false;
            enqueue(qData, &front, &rear);
        }
    }
    return sum_left_leaves;
}


int sum_of_left_leaves(struct tNode *root) {
    return bfs_mod(root);
}

// client


int main() {
	// create a binary tree
	struct tNode *root = newtNode(20);
	root->left = newtNode(9);
	root->right = newtNode(49);
	root->left->left = newtNode(5);
	root->left->right = newtNode(12);
	root->right->left = newtNode(23);
	root->right->right = newtNode(52);
	root->left->right->right = newtNode(15);
	root->right->right->left = newtNode(50);
	printf("%d", sum_of_left_leaves(root));
	getch();
}
