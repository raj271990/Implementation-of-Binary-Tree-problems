#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

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
    if(current == NULL) return;
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

// Level order
levelorder(struct tNode *current) {
    int level = 1;
    bool hasLevelChanged = true;
    struct tNode *marker = newtNode(INT_MIN);
    struct qNode *front = NULL, *rear = NULL;
    enqueue(current, &front, &rear);
    enqueue(marker, &front, &rear);
    while(!isEmpty(&front)) {
        current = dequeue(&front, &rear);
        if(current == marker) {
            if(isEmpty(&front)) return;
            level = level + 1;
            hasLevelChanged = true;
            enqueue(marker, &front, &rear);
        }
        else {
            if(hasLevelChanged) {
                printf("%d ", current->val);
                hasLevelChanged = false;
            }
            enqueue(current->left, &front, &rear);
            enqueue(current->right, &front, &rear);
        }
    }
}


// client

int main() {
	// create a binary tree
	struct tNode *root = newtNode(12);
	root->left = newtNode(10);
	root->right = newtNode(30);
	root->right->left = newtNode(25);
	root->right->right = newtNode(40);
	// pass the tree for doing level order traversal
	levelorder(root);
	getch();
}
