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

// function to find root to leaf path with maximum sum

update_max_sum_tglf(struct tNode *root, int curr_sum, int *max_sum_ref, struct tNode **target_leaf_ref) {
    if(root == NULL) return;
    // update current sum
    curr_sum = curr_sum + root->val;
    if(root->left == NULL && root->right == NULL) {
        if(curr_sum > *max_sum_ref) {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = root;
        }
    }
    // traverse the tree
    update_max_sum_tglf(root->left, curr_sum, max_sum_ref, target_leaf_ref);
    update_max_sum_tglf(root->right, curr_sum, max_sum_ref, target_leaf_ref);
}

bool is_tglf_In_Tree(struct tNode *root, struct tNode *target_leaf) {
    if(root == NULL) return false;
    if(root == target_leaf) {
        printf("%d ", target_leaf->val);
        return true;
    }
    if(is_tglf_In_Tree(root->left, target_leaf)) {
        printf("%d ", root->val);
        return true;
    }
    if(is_tglf_In_Tree(root->right, target_leaf)) {
        printf("%d ", root->val);
        return true;
    }
    return false;
}

max_sum_root_to_leaf(struct tNode *root) {
    // print max sum and get pointer to target leaf
    int max_sum = INT_MIN, curr_sum = 0;
    struct tNode *target_leaf = NULL;
    // Call function to update max_sum and target leaf
    update_max_sum_tglf(root, curr_sum, &max_sum, &target_leaf);
    
    // Print max sum and value of target leaf
    printf("Maximum Sum = %d", max_sum);
    printf("\n");
    printf("Target Leaf Value = %d", target_leaf->val);
    
    // Now we already printed the max_sum and also have a pointer to the target. Now we need
    // to print the root to lef path
    //Let's call a function to do this
    printf("\n");
    bool is_true = is_tglf_In_Tree(root, target_leaf);
}

//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(10);
	root->left = newtNode(-2);
	root->right = newtNode(7);
	root->left->left = newtNode(8);
	root->left->right = newtNode(-4);
	max_sum_root_to_leaf(root);
	getch();
}
