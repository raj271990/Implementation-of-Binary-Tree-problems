#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// structure of tree node

struct tNode {
	struct tNode *left;
	int val;
	struct tNode *right;
};

// structure of stack node

struct sNode {
	struct tNode *tptr;
	struct sNode *next;
};

// create new tree node and return

struct tNode * new_tNode(int val) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = val;
	x->right = NULL;
	return x;
}

// Create new stack node and return

struct sNode * new_sNode(struct tNode *tptr) {
	struct sNode *x = (struct sNode *)malloc(sizeof(struct sNode));
	x->tptr = tptr;
	x->next = NULL;
	return x;
}

// push tree node pointers to stack

push(struct tNode *current, struct sNode **topref) {
	//if pushing as first node
	if((*topref) == NULL) *topref = new_sNode(current);
	else {
		struct sNode *oldtop = *topref;
		*topref = new_sNode(current);
		(*topref)->next = oldtop;
		oldtop = NULL;
	}
}



// pop tree nodes from stack


struct tNode * pop(struct sNode **topref) {
	struct tNode *x = (*topref)->tptr;
	*topref = (*topref)->next;
	return x;
}


// Check for empty stack

bool isEmpty(struct sNode **topref) {
	return ((*topref) == NULL);
}


// Inorder without recursion

inorderWR(struct tNode *current) {
	struct sNode *top = NULL;
	while(current != NULL || !isEmpty(&top)) {
		if(current != NULL) {
			push(current, &top);
			current = current->left;
		}
		else {
			current = pop(&top);
			printf("%d ", current->val);
			current = current->right;
		}
	}
}




// Client program

int main() {
	struct tNode *root = new_tNode(1);
	root->left = new_tNode(2);
	root->right = new_tNode(3);
	root->left->left = new_tNode(4);
	root->left->right = new_tNode(5);
	inorderWR(root);
	getch();
}
