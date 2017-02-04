// Post order traversal without recursion - using 2 stacks


#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

// Creating structure of result stack
struct rsNode {
    int i;
    struct rsNode *next;
};

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

//create rs node function push pop and empty check functions for result stack

struct rsNode * newrsNode(int i){
    struct rsNode *x = (struct rsNode *)malloc(sizeof(struct rsNode));
    x->i=i;
    x->next=NULL;
    return x;
}

rspush(int i, struct rsNode **rstopref) {
    if(*rstopref == NULL) {
        *rstopref = newrsNode(i);         
    }
    else {
        struct rsNode *oldrstop = *rstopref;
        *rstopref = newrsNode(i);
        (*rstopref)->next=oldrstop;
    }
}

int rspop(struct rsNode **rstopref) {
    int x=(*rstopref)->i;
    *rstopref = (*rstopref)->next;
    return x;
}

bool isrsEmpty(struct rsNode *rstop) {
    return rstop == NULL;
}

// Preorder without recursion

PRLWR(struct tNode *current, struct rsNode **rstopref) {
	struct sNode *top = NULL;
	while(!isEmpty(&top) || current != NULL) {
		if(current!=NULL) {
			rspush(current->val,rstopref);//printf("%d ", current->val);
			push(current, &top);
			current = current->right;
		}
		else {
			current = pop(&top);
			current = current->left;
		}
	}
}


postorderWR(struct tNode *root) {
    struct rsNode *rstop = NULL;
     PRLWR(root, &rstop);
     while(!isrsEmpty(rstop)) {
         printf("%d ", rspop(&rstop));
     }
}

// Client program

int main() {
	struct tNode *root = new_tNode(1);
	root->left = new_tNode(2);
	root->right = new_tNode(3);
	root->left->left = new_tNode(4);
	root->left->right = new_tNode(5);
	postorderWR(root);
	getch();
}
