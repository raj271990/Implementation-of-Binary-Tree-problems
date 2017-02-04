// Ancestors of a key - best approach ?
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

// Function to print ancestors
bool isKeyExist(struct tNode *root, int key) {
    if(root == NULL) return false;
    if(root->val == key) return true;
    if(isKeyExist(root->left,key) || isKeyExist(root->right,key)) {
        printf("%d ",root->val);
        return true;
    }
    return false;
}

//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = NULL; //newtNode(4);
	root->left->right = NULL; //newtNode(5);
	root->right->left = newtNode(6);
	root->right->right = newtNode(7);
	bool b = isKeyExist(root,7);
	getch();
}
