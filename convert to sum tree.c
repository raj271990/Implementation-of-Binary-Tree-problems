#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

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

// Value of 
int valueOf(struct tNode *current) {
    if(current == NULL) return 0;
    return current->val;
}

// Convert to sum tree
to_Sum_Tree(struct tNode *root) {
    if(root == NULL) return;
    int a = valueOf(root->left);
    int b = valueOf(root->right);
    to_Sum_Tree(root->left);
    to_Sum_Tree(root->right);
    root->val = a + valueOf(root->left) + b + valueOf(root->right);
}


inorder(struct tNode *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
	// create a binary tree
	struct tNode *root = newtNode(10);
	root->left = newtNode(-2);
	root->right = newtNode(6);
	root->left->left = newtNode(8);
	root->left->right = newtNode(-4);
	root->right->left = newtNode(7);
	root->right->right = newtNode(5);
	// pass the tree for doing level order traversal
	to_Sum_Tree(root);
	inorder(root);
	getch();
}
