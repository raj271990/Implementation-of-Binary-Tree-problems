#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>



// structure of tree node
struct tNode {
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

// Calculate height of tree


int height(struct tNode *root) {
    if(root == NULL) return 0;
    return (maxOf(height(root->left), height(root->right)) + 1);
}

// function to return lesser of two values
int lesserOf(int n1, int n2) {
    if(n1<=n2) return n1;
    return n2;
}

// Calculate maximum of two integer values 


int maxOf(int i, int j) {
    if(i>=j) return i;
    return j;
}


// Find common element of two arrays from end
int commonEle(int arr1[], int arr2[], int len) {
    int i;
    for(i=len; i>=0; i--) {
        if(arr1[i] == arr2[i]) return arr1[i];    
    }
    return INT_MIN;
}



// update path function
int updatepath(struct tNode *root, int path[], int n, int level) {
    if(root == NULL) return -1;
    path[level] = root->val;
    if(root->val == n) return level;
    int l1 = updatepath(root->left, path, n, level+1);
    if(l1 != -1) return l1;
    return (updatepath(root->right, path, n, level+1));
}



// LCA
int lca(struct tNode *root, int n1, int n2) {
    int h = height(root);
    int path1[h], path2[h];
    int l1 = updatepath(root, path1, n1, 0);
    int l2 = updatepath(root, path2, n2, 0);
    int l = lesserOf(l1, l2);
    return commonEle(path1, path2, l);
}



// Client
int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	root->right->left = newtNode(6);
	root->right->right = newtNode(7);
	// Call lca
    printf("%d", lca(root, 7, 7));
	getch();
}
