#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// structure of tree node

struct tNode{
  int data;
  struct tNode* left;
  struct tNode* right;
  struct tNode* nextright;  
};


// structure of queue node

struct qNode {
    struct tNode *tptr;
    int tNodeLevel;
    struct qNode *next;
};


// Create a tree  node
struct tNode * newtNode(int data) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->data = data;
	x->left = NULL;
	x->right = NULL;
	x->nextright = NULL;
	return x;
}


// Create a queue node

struct qNode * newqNode(struct tNode *tptr, int tNodeLevel) {
    struct qNode *x = (struct qNode *)malloc(sizeof(struct qNode));
    x->tptr = tptr;
    x->tNodeLevel = tNodeLevel;
    x->next = NULL;
    return x;
}

// Enqueue function

enqueue(struct tNode *tptr, int tNodeLevel, struct qNode **frontref, struct qNode **rearref) {
    // if inserting as first node
    if(*frontref == NULL) {
        *rearref = newqNode(tptr, tNodeLevel);
        *frontref = *rearref;
    }
    else {
        (*rearref)->next = newqNode(tptr, tNodeLevel);
    }
}

// Dequeue function

struct tNode * dequeue(struct qNode **frontref, struct qNode **rearref) {
    struct tNode *x = (*frontref)->tptr;
    *frontref = (*frontref)->next;
    // Check if front gets null, if yes make rear null as well
    if((*frontref) == NULL) *rearref = NULL;
    return x;
}




// Get tree node pointer at the front of the queue

struct tNode * gettNodePointerAtFront(struct qNode **frontref) {
    return ((*frontref)->tptr);
}


// Check if queue empty
bool isEmpty(struct qNode **frontref) {
    return (*frontref == NULL);
}

// Get level of tree node at front of the queue

int getLevelAtFront(struct qNode **frontref) {
    if(!isEmpty(frontref)) {
        return (*frontref)->tNodeLevel;
    }
    return -1;
}


bfsExtention(struct tNode *tptr) {
    int tNodeLevel = 0;
    struct qNode *front = NULL,*rear = NULL;
    enqueue(tptr, tNodeLevel, &front, &rear);
    while(!isEmpty(&front)) {
        int x_level = getLevelAtFront(&front);
        struct tNode *x = dequeue(&front,&rear);
        if(x_level == getLevelAtFront(&front)) {
            x->nextright = gettNodePointerAtFront(&front);
        }
    }
}

int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	// pass the tree for doing level order traversal
	bfsExtention(root);
	getch();
}
