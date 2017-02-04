#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// sruct of tree node

struct tNode {
    struct tNode *left;
    char c;
    struct tNode *right;
};

// create new tree node

struct tNode * newtNode(char c) {
    struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
    x->left = NULL;
    x->c=c;
    x->right=NULL;
    return x;
}

// Finding the index of plr[k] in lpr[]
int indexOf(char c, char lpr[], int i, int j) {
    int k = i;
    while(k<=j) {
        if(lpr[k] == c) return k;
        k++;
    }
}

// construct tree from given oinorder and preorder traversal

struct tNode * consTree(char lpr[], int i, int j, char plr[], int k, int l, struct tNode *root) {
    //Base 
    if(j<i) return NULL;
    // Inductve step
    root = newtNode(plr[k]);
    int pos = indexOf(plr[k], lpr, i, j);
    root->left = consTree(lpr, i, pos-1, plr, k+1, k+pos-i, root->left);
    root->right = consTree(lpr, pos+1, j, plr, k+pos-i+1, l, root->right);
    return root;
}

// Inorder traversal - to verify result

inorder(struct tNode *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%c ", root->c);
    inorder(root->right);    
}

// client

int main() {
    char lpr[6] = {'d', 'b', 'e', 'a', 'f', 'c'};
    char plr[6] = {'a','b', 'd', 'e', 'c', 'f'};
    struct tNode *root = NULL;
    root = consTree(lpr, 0,5, plr, 0,5, root);
    inorder(root);
    getch();
    return 0;
}
