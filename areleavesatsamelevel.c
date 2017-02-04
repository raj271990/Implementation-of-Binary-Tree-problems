// Are leaves at same level
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

// Function to check, if leaves are same level
bool areLeavesAtLevel(int *L, struct tNode *root, int level) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) {
        if(*L == INT_MIN) *L = level;
        return (*L == level);
    }
    return(areLeavesAtLevel(L, root->left, level+1) &&
           areLeavesAtLevel(L, root->right, level+1));
}

bool checkLeavesAtSameLevel(struct tNode *root) {
    int init_level = INT_MIN;
    return areLeavesAtLevel(&init_level, root, 1);
}

//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	//root->right = newtNode(3);
	//root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	//root->right->left = newtNode(6);
	//root->right->right = newtNode(7);
	printf("%x", checkLeavesAtSameLevel(root));
	getch();
}
