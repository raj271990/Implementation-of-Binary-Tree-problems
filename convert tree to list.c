#include<stdio.h>
#include<conio.h>
#include<stdbool.h>


// Sructure of tree node
struct tNode {
	struct tNode *left;
	int val;
	struct tNode *right;
};

// structure of list node
struct lNode {
	struct lNode *prev;
	int val;
	struct lNode *next;
};

//Helper function to create a new list node
struct lNode * newlNode(int val) {
	struct lNode *x = (struct lNode *)malloc(sizeof(struct lNode));
	x->prev = NULL;
	x->val = val;
	x->next = NULL;
	return x;
}


// Helper to create new tree node

struct tNode * newtNode(int nodeData) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = nodeData;
	x->right = NULL;
	return x;
}

// Function which will keep inserting new nodes to the existing doubly linked list
listInsert(struct lNode **headref, int val) {
	// If inserting as first node
	if(*headref == NULL) *headref = newlNode(val);
	else {
		struct lNode *oldhead = *headref;
		*headref = newlNode(val);
		(*headref)->next = oldhead;
		oldhead->prev = *headref;
		oldhead = NULL;
	}
}

// Function to perform inorder traversal and calling listInsert to keep inserting tree 
// elements as list nodes.

inorder(struct tNode *root, struct lNode **headref) {
	if(root == NULL) return;
	inorder(root->right, headref);
	listInsert(headref,root->val);
	inorder(root->left, headref);
}

// function to convert a tree to a doubly linked list

convertToDLL(struct tNode *root, struct lNode ** headref) {
	inorder(root, headref);
} 


// client

int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	// we want to convert the above tree into a doubly linked list
	// so we need a head node
	struct lNode *head = NULL;
	// we will now call the function which will convert the tree to DLL pointed by above //head node
	convertToDLL(root,&head);
	// Now we need to check if the function successfully converted the tree to DLL. For that we would need to print the list. we need to loop through the list printing its nodes
	struct lNode *current = head;
	while(current->next != NULL) {
        printf("%d=", current->val);
        current = current->next;
    }
    printf("%d", current->val);
    getch();
}
