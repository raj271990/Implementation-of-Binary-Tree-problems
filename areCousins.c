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


int getLevel(struct tNode *root, int n, int level) {
    if(root == NULL) return -1;
    if(root->val == n) return level;
    int l = getLevel(root->left, n, level+1);
    if(l!=-1) return l;
    return getLevel(root->right,n,level+1);
}

bool areSiblings(struct tNode *root, int n1, int n2) {
    if(root == NULL) return false;
    if(root->left != NULL && root->right != NULL) {
        if((root->left->val == n1 && root->right->val == n2) || (root->left->val == n2 && root->right->val == n1)) return true;
    }
    return (areSiblings(root->left,n1,n2) || areSiblings(root->right,n1,n2));
}


bool areCousins(struct tNode *root, int n1, int n2) {
    if(getLevel(root,n1,0) == getLevel(root,n2,0)) return !areSiblings(root,n1,n2);
    return false;
}


int main() {
	// create a binary tree
	struct tNode *root = newtNode(20);
	root->left = newtNode(8);
	root->right = newtNode(22);
	root->left->left = newtNode(4);
	root->right->right = newtNode(12);
	//root->left->right = newtNode(12);
	//root->left->right->left = newtNode(10);
	//root->left->right->right = newtNode(14);
    printf("%d", areCousins(root,8,12));
	getch();
}
