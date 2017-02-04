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


// structure of q data

struct qData {
    struct tNode *tptr;
    int level;
};



// Structure of queue Node
struct qNode {
	struct qData qNodeData;
	struct qNode *next;
};

// create new queue node

struct qNode * newqNode(struct qData qNodeData) {
	struct qNode *x = (struct qNode *)malloc(sizeof(struct qNode));
	x->qNodeData = qNodeData;
	x->next = NULL;
	return x;
}


// Enqueue 

enqueue(struct qData qNodeData, struct qNode **frontref, struct qNode **rearref) {
	// if inserting as first node in queue
	if((*frontref) == NULL) {
		*rearref = newqNode(qNodeData);
		*frontref = *rearref;
	}
	else {
		struct qNode *oldrear = *rearref;
		*rearref =newqNode(qNodeData);
		oldrear->next = *rearref;
	}
}


// Dequeue - returns pointer to tree node
struct qData dequeue(struct qNode **frontref, struct qNode **rearref) {
	// get the value of front node
	struct qData qNodeData = (*frontref)->qNodeData;
	// remove the front member from the queue
	(*frontref) = (*frontref)->next;
	// Check if no member in queue...if thats the case, there there wouldnt be any member // at the back of te queue as well
	if((*frontref) == NULL) (*rearref) = NULL;
	// return the stored value pointed earlier by front
	return qNodeData;
}

// check if queue empty
bool isEmpty(struct qNode **frontref) {
   // printf("frontref = %d\n",(*frontref)->tptr->val);
	return((*frontref) == NULL);
}

// level order traversal line by line

levelOrder(struct tNode *current) {
    struct qNode *front = NULL, *rear = NULL;
    int prev_level =0, curr_level = 0;
    struct qData qNodeData;
    struct tNode *curr_tNode = NULL;
    // Get ready with data to be inserted into queue
    qNodeData.tptr = current;
    qNodeData.level = curr_level;
    // Enqueue
    enqueue(qNodeData, &front, &rear);
    while(!isEmpty(&front)) {
        // Deqeue
        qNodeData = dequeue(&front, &rear);
        curr_tNode = qNodeData.tptr;
        curr_level = qNodeData.level;
        // check if current level matches with previous level. If no the print a new line before printing the tree node value
        if(curr_level > prev_level) {
            prev_level = curr_level;
            printf("\n");
        }
        printf("%d ", curr_tNode->val);
        // enqueue left and right child
        if(curr_tNode->left != NULL) {
            qNodeData.tptr = curr_tNode->left;
            qNodeData.level = curr_level + 1;
            enqueue(qNodeData, &front, &rear);
        }
        if(curr_tNode->right != NULL) {
            qNodeData.tptr = curr_tNode->right;
            qNodeData.level = curr_level + 1;
            enqueue(qNodeData, &front, &rear);
        }
    }
    
}



// client

int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	// pass the tree for doing level order traversal
	levelOrder(root);
	getch();
}



















