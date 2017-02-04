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


// Sum of left leaves
/*
int sum_left_leaves(struct tNode *root) {
    if(root == NULL) return 0;
    if(root->left != NULL) { 
        if(root->left->left == NULL & root->left->right == NULL) return root->left->val + sum_left_leaves(root->right);
    }
    return sum_left_leaves(root->left) + sum_left_leaves(root->right);
}
*/

// /*
sum_left_leaves(struct tNode *root, int *sumref, bool isLeftLeaf) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL && isLeftLeaf) {
        *sumref = (*sumref) + root->val;
    }
    sum_left_leaves(root->left, sumref, true);
    sum_left_leaves(root->right, sumref, false);
}
// */

int main() {                     
	// create a binary tree
	struct tNode *root = newtNode(20);
	root->left = newtNode(9);
	root->right = newtNode(49);
	root->left->left = newtNode(5);
	root->left->right = newtNode(12);
	root->right->left = newtNode(23);
	root->right->right = newtNode(52);
	root->left->right->right = newtNode(15);
	root->right->right->left = newtNode(50);
	int sum = 0;
	sum_left_leaves(root, &sum, false);
	printf("%d", sum);
	//printf("%d", sum_left_leaves(root));
	getch();
}
