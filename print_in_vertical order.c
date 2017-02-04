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

// Function to return maximum of three values
int maxOf(int a, int b, int c) {
	int max;
	if(a>=b) max = a;
	else max = b;
	if(c > max) return c;
	return max;
}

// Function to return minimum of 3 values
int minOf(int a, int b, int c) {
	int min;
	if(a<=b) min = a;
	else min = b;
	if(c < min) return c;
	return min;
}

// Function to get the distance of left most node in a tree from root which is at vertical // level 0

int get_Dist_Of_Left_Most_Node(struct tNode *root, int v_level) {
	if(root == NULL) return 0;
	return minOf(get_Dist_Of_Left_Most_Node(root->left, v_level-1), get_Dist_Of_Left_Most_Node(root->right, v_level+1), v_level);
}
 
// Function to get the distance of right most node in a tree from root which is at vertical // level 0 

int get_Dist_Of_Right_Most_Node(struct tNode *root, int v_level) {
	if(root == NULL) return 0;
	return maxOf(get_Dist_Of_Right_Most_Node(root->left, v_level-1), get_Dist_Of_Right_Most_Node(root->right, v_level+1), v_level);
}

// Function to print given vertical level - private function

printVerticalLevel(struct tNode *root, int v_level) {
    if(root == NULL) return;
    if(v_level == 0) printf("%d ", root->val);
    printVerticalLevel(root->left, v_level+1);
    printVerticalLevel(root->right, v_level-1);
}

// Called by client to print tree in vertical order
printInVerticalOrder(struct tNode *root) {
	int dLeft, dRight, v_level;
	dLeft = get_Dist_Of_Left_Most_Node(root,0);
	dRight = get_Dist_Of_Right_Most_Node(root,0);
	// print each level from d1 to d2
	for(v_level=dLeft; v_level<=dRight; v_level++) {
		printVerticalLevel(root, v_level);
		printf("\n");
	}
}


int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	root->right->left = newtNode(6);
	root->right->right = newtNode(7);
	root->right->left->right = newtNode(8);
	root->right->right->right = newtNode(9);
	printInVerticalOrder(root);
	getch();
}
