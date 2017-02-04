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


// exhange two elements in an array
exchg(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// returns index of an element, when searched in an array, we are sure that the element exists
int indexOf(int ele, int arr[], int i, int j) {
    int k;
    for(k=i;k<=j;k++) {
        if(ele == arr[k]) return k;
    }
    return INT_MAX; //  In case not found; just make this function somewhat robust
}


// resuffle function
int reshuffle(int lv[], int k, int l, int in[], int i, int j, int p) {
    int r = k-1, s, pos;
    for(s = k;s<=l;s++) {
        pos = indexOf(lv[s],in,i,j);
        if(pos<p) {
            r = r + 1;
            exchg(lv,r,s);
        }
    }
    return r;
}

// Construct Tree from inorder and level order traversal
struct tNode * constructTree(struct tNode *root, int in[], int i, int j, int lv[], int k, int l) {
    //Base
    if(i > j) return NULL;
    // Inductive
    int p = indexOf(lv[i],in,k,l);
    //printf("a ");
    // Root node is value at index p in inorder array
    root = newtNode(in[p]);
    // Call reshuffle of level order array
    int q = reshuffle(lv,k+1,l,in,i,j,p);
    // Elements at index q or <q in level order array belongs to left subtree and those at >q belongs to right subtree
    // Recurse for left and right subtrees
    root->left = constructTree(root->left,in,i,p-1,lv,k+1,q);
    root->right = constructTree(root->right,in,p+1,j,lv,q+1,l);
    return root;
}


// Inorder Traversal - to verify result

inorder(struct tNode *root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Client
int main() {
    //printf("I am here");
    int in[2] = {1,2}; //{4,8,10,12,14,20,22};
    int lv[2] = {1,2}; //{20,8,22,4,12,10,14};
    struct tNode *root = NULL;
    //printf("I am here");
    root = constructTree(root,in,0,0,lv,0,0);
    // Call inorder to verify
    inorder(root);
    getchar();
    return 0;
}
