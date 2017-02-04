#include<stdio.h>
#include<conio.h>
#include<stdbool.h>


// Sructure of tree node
struct tNode {
	struct tNode *left;
	int val;
	struct tNode *right;
};

// Structure of queue Node
struct qNode {
	struct tNode *tptr;
	struct qNode *next;
};

// create new tree node

struct tNode * newtNode(int nodeData) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = nodeData;
	x->right = NULL;
	return x;
}

// Create new queue node
struct qNode * newqNode(struct tNode *current) {
	struct qNode *rear = (struct qNode *)malloc(sizeof(struct qNode));
	rear->tptr = current;
	rear->next = NULL;
	return rear;
}

// Enqueue

enqueue(struct tNode *current, struct qNode **frontref, struct qNode **rearref) {
	// if inserting as first node in queue
	if((*frontref) == NULL) {
		*rearref = newqNode(current);
		*frontref = *rearref;
	}
	else {
		struct qNode *oldrear = *rearref;
		*rearref =newqNode(current);
		oldrear->next = *rearref;
	}
}

// Dequeue - returns pointer to tree node
struct tNode * dequeue(struct qNode **frontref, struct qNode **rearref) {
	// get the value of front node
	struct tNode *x = (*frontref)->tptr;
	// remove the front member from the queue
	(*frontref) = (*frontref)->next;
	// Check if no member in queue...if thats the case, there there wouldnt be any member // at the back of te queue as well
	if((*frontref) == NULL) (*rearref) = NULL;
	// return the stored value pointed earlier by front
	return x;
}

// check if queue empty
bool isEmpty(struct qNode **frontref) {
   // printf("frontref = %d\n",(*frontref)->tptr->val);
	return((*frontref) == NULL);
}

// Level order traversal of tree
levelOrder(struct tNode *root) {
	if(root == NULL) return;
	struct qNode *front = NULL, *rear = NULL;
	enqueue(root, &front,&rear);
	while(!isEmpty(&front)) {
		struct tNode *x = dequeue(&front, &rear);
		printf("%d ", x->val);
		if(x->left != NULL) enqueue(x->left, &front, &rear);
		if(x->right != NULL) enqueue(x->right, &front, &rear);
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
