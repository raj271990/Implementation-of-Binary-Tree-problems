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

// Calculate height of tree


int maxOf(int i, int j) {
    if(i>=j) return i;
    return j;
}

int height(struct tNode *root) {
    if(root == NULL) return 0;
    return (maxOf(height(root->left), height(root->right)) + 1);
}

// Update max_path function
update_max_path(int max_path[], int current_path[], int level) {
    int i;
    for(i=0;i<=level;i++) {
        max_path[i] = current_path[i];
    }
}


// Print max path
print_max_path(int max_path[], int max_path_length) {
    int i;
    for(i=max_path_length;i>=0;i--) {
        printf("%d  ", max_path[i]);
    }
}


// Max path Sum
maxPathSum(struct tNode *current, int current_path[], int current_path_sum,
                                  int max_path[], int *max_path_sum, int *max_path_length,
                                  int total_leaf_count, int *current_leaf_count_ref,
                                  int level) {
     //printf("\nmaxpathsum = %d",*max_path_sum );
    if(current == NULL) return;
    
    current_path[level] = current->val;
    current_path_sum = current_path_sum + current->val;
    
    // if leaf node
    if(current->left == NULL && current->right == NULL) {
        *current_leaf_count_ref = *current_leaf_count_ref + 1;
        if(current_path_sum > *max_path_sum) {
            *max_path_sum = current_path_sum;
            update_max_path(max_path, current_path, level);
            *max_path_length = level;
        }
        if(*current_leaf_count_ref == total_leaf_count) {
            print_max_path(max_path, *max_path_length);
            printf("\n");
            printf("max_path_sum = %d", *max_path_sum);
            return;
        }
    }
    //Recurse on left and right subtrees
    maxPathSum(current->left, current_path, current_path_sum,
                              max_path, max_path_sum, max_path_length,
                               total_leaf_count, current_leaf_count_ref,
                               level+1);
    maxPathSum(current->right, current_path, current_path_sum,
                              max_path, max_path_sum, max_path_length,
                               total_leaf_count, current_leaf_count_ref,
                               level+1);
}

//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(10);
	root->left = newtNode(-2);
	root->right = newtNode(7);
	root->left->left = newtNode(8);
	root->left->right = newtNode(-4);
    int h = height(root);
    int current_path[h], max_path[h];
    int current_path_sum =0, max_path_sum = INT_MIN, max_path_length =0,total_leaf_count =3, current_leaf_count=0,level =0;
	maxPathSum(root, current_path, current_path_sum,
                     max_path, &max_path_sum, &max_path_length,
                     total_leaf_count, &current_leaf_count,
                     level);
	getch();
}
