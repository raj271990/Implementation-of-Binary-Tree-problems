// Reverse level order

// we would need to use a stack.
// While enqueing into the queue, we would need to enqueue right and then enqueue left

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>


// Sructure of tree node
struct tNode {
	struct tNode *left;
	int val;
	struct tNode *right;
};



// create new tree node

struct tNode * newtNode(int nodeData) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = nodeData;
	x->right = NULL;
	return x;
}

// Structure of queue Node
struct qNode {
	struct tNode *tptr;
	struct qNode *next;
};



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


// structure of stack node

struct sNode {
    int val;
    struct sNode *next;
};

// create new stack node

struct sNode * newsNode(int sData) {
    struct sNode *x = (struct sNode *)malloc(sizeof(struct sNode));
    x->val = sData;
    x->next = NULL;
    return x;
}


// push

push(int val, struct sNode **topref) {
    struct sNode *x = newsNode(val);
    x->next = *topref;
    *topref = x;
    x = NULL;
}

// pop

int pop(struct sNode **topref) {
    int val = (*topref)->val;
    (*topref) = (*topref)->next;
    return val;
}

// check for empty stack 

bool issEmpty(struct sNode **topref) {
    return((*topref) == NULL);
}


// function to print tree in reverse level order in o(n) time

bfs_mod(struct tNode *current) {
    struct qNode *front = NULL, *rear = NULL;
    struct sNode *top = NULL;
    struct tNode *x = NULL;
    enqueue(current, &front, &rear);
    while(!isEmpty(&front)) {
        x = dequeue(&front, &rear);
        push(x->val, &top);
        if(x->right != NULL) enqueue(x->right, &front, &rear);
        if(x->left != NULL) enqueue(x->left, &front, &rear);
    }
    // pop stack while not empty
    while(!issEmpty(&top)) {
        printf("%d ", pop(&top));
    }
}



reverseLevelOrder(struct tNode *root) {
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
	// pass the tree for doing level order traversal
	reverseLevelOrder(root);
	getch();
}








