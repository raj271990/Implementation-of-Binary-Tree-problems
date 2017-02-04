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



int maxOf(int i, int j) {
    if(i>=j) return i;
    return j;
}

// Calculate height of tree


int height(struct tNode *root) {
    if(root == NULL) return 0;
    return (maxOf(height(root->left), height(root->right)) + 1);
}


printArr(int arr[], int len) {
    int i;
    for(i=0;i<=len;i++) printf("%d ", arr[i]);
}

bool _ancestorsExists(struct tNode *root, int anc[], int level, int key) {
    if(root == NULL) return false;
    anc[level] = root->val;
    if(root->val == key) {
        printArr(anc, level);
        return true;
    }
    return(_ancestorsExists(root->left, anc, level+1, key) || 
           _ancestorsExists(root->right, anc, level+1, key));
}

ancestors(struct tNode *root, int key) {
    int h = height(root);
    int anc[h];
    bool b = _ancestorsExists(root, anc, 0, key);
}


//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	root->right->left = newtNode(6);
	root->right->right = newtNode(7);
	bool b = ancestors(root,7);
	getch();
}
