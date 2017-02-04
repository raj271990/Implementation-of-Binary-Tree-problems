// Connect nodes at same level


#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// Tree structure is slightly different in this case

struct tNode {
    struct tNode *left;
    int val;
    struct tNode *right;
    struct tNode *nextright;
};

// create new tree node - Initially all next right pointers will be set to null

struct tNode * newtNode(int val) {
    struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
    x->left = NULL;
    x->val = val;
    x->right=NULL;
    x->nextright=NULL;
    return x;   
}


// Function to connect nodes t same level

connNodesAtLevel(struct tNode *root) {
    //Base
    if(root == NULL) return;
    if(root->left != NULL) root->left->nextright = root->right;
    // Inductive
    connNodesAtLevel(root->left);
    connNodesAtLevel(root->right);
}


// Client

int main() {
    struct tNode *root = NULL;
    root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
    connNodesAtLevel(root);
    printf("%d\n", root->left->nextright->val);
    root=root->left;
    printf("%d\n", root->val);
    printf("%d", root->left->nextright->val);
    getch();
}







