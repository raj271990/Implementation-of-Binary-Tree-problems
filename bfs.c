#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// BFS 

// construct a tree Node

struct tNode {
    struct tNode *left;
    int val;
    struct tNode *right;
};

// structure of queue Node
struct qNode {
    struct tNode *val;
    struct qNode *next;
};

// Return a new tree node

struct tNode * newtNode(int val) {
    struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
    x->val = val;
    x->left = NULL;
    x->right = NULL;
    return x;
}

// enqueue function 

enqueue(struct qNode **prear,struct qNode **pfront, struct tNode *current) {
    struct qNode *oldrear = *prear;
    *prear = (struct qNode *)malloc(sizeof(struct qNode));
    (*prear)->val = current;
    (*prear)->next = NULL;
    if(oldrear != NULL) {
        oldrear->next = (*prear);
    }
    else //first Node inserted
        (*pfront) = (*prear);
    oldrear = NULL;
}


// Dequeue function of queue

struct tNode * dqueue(struct qNode **pfront, struct qNode **prear) {
    struct tNode *x = (*pfront)->val;
    (*pfront) = (*pfront)->next;
    if((*pfront) == NULL) *prear == NULL;
    return x;
}

// check if queue empty

bool isEmpty(struct qNode **pfront) {
    return ((*pfront) == NULL);
}

// BFS

bfs(struct tNode *root) {
    struct qNode *front = NULL, *rear = NULL;
    if(root == NULL) return;
    enqueue(&rear, &front,root);
    while(!isEmpty(&front)) {
        struct tNode *x = dqueue(&front, &rear);
        printf("%d ", x->val);
        if(x->left != NULL) enqueue(&rear,&front,x->left);
        if(x->right!= NULL) enqueue(&rear,&front, x->right);
    }
}

//client

int main() {
    struct tNode *root;
    root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
    bfs(root);
    getch();
}









