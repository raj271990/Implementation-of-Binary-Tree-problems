// Sumtree check

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// sruct of tree node

struct tNode {
    struct tNode *left;
    int val;
    struct tNode *right;
};

// create new tree node

struct tNode * new_tNode(int val) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = val;
	x->right = NULL;
	return x;
}

int sum(struct tNode *curr) {
    if(curr == NULL) return 0;
    if(curr->left == NULL && curr->right == NULL) return curr->val;
    return 2*(curr->val);
}

bool isSumTree(struct tNode *root) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(isSumTree(root->left) && isSumTree(root->right)) 
        return(root->val == sum(root->left) + sum(root->right));
     return false;
}

int main() {
    // construct S
	struct tNode *root1 = new_tNode(26);
	root1->left = new_tNode(13);
	//root1->right = new_tNode(2);
	root1->left->left = new_tNode(7);
	root1->left->right = new_tNode(5);
	//root1->right->right = new_tNode(3);*/
	// Construct T
	struct tNode *root2 = new_tNode(1);
	//root2->left = new_tNode(4);
	//root2->right = new_tNode(5);
	//root2->left->left = new_tNode(4);
	//root2->left->right = new_tNode(5);
	// Call subtree check function
	printf("%d", isSumTree(root1));
	getch();
	return 0;
}
