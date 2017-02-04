// Iterative minimum depth

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// tree structure and related utility function
struct tNode {
    struct tNode *left;
    int val;
    struct tNode *right;
};

struct tNode * newtNode(int val) {
    struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
    x->left = NULL;
    x->val = val;
    x->right = NULL;
    return x;
}

// stack structure and  related functions

struct cus_sData {
    struct tNode *tNode_ptr;
    int tNode_depth;
};

struct sNode {
    struct cus_sData sData;
    struct sNode *next;
};

push(struct cus_sData sData, struct sNode **topref) {
    struct sNode *x = (struct sNode *)malloc(sizeof(struct sNode));
    x->sData = sData;
    x->next = (*topref);
    (*topref) = x;
    x = NULL;
}


struct cus_sData pop(struct sNode **topref) {
    struct cus_sData sData = (*topref)->sData;
    (*topref) = (*topref)->next;
    return sData;
}


bool issEmpty(struct sNode **topref) {
    return ((*topref) == NULL);   
}

// Iterative get minimum depth


int min_Of(int a, int b) {
    if(a<=b) return a;
    return b;
}

int getMinimumDepth(struct tNode *current) {
    if(current == NULL) return INT_MAX;
    if(current->left == NULL && current->right == NULL) return 0;
    
    int curr_depth = 0;
    int min_depth = INT_MAX;
    
    struct cus_sData sData;
    
    struct sNode *top = NULL;
    
    while(current != NULL || !issEmpty(&top)) {
        if(current != NULL) {
            if(current->left == NULL && current->right == NULL) {
                min_depth = min_Of(min_depth, curr_depth);
            }
            // push and move left
            sData.tNode_ptr = current;
            sData.tNode_depth = curr_depth;
            push(sData, &top);
            current = current->left;
            curr_depth = curr_depth + 1;
        }
        else {
            sData = pop(&top);
            current = sData.tNode_ptr;
            curr_depth = sData.tNode_depth;
            current = current->right;
            curr_depth = curr_depth + 1;
        }
    }
    return min_depth;
}


//client 
int main() {
	// create a binary tree
	struct tNode *root = newtNode(10);
	root->left = newtNode(-2);
	root->right = newtNode(7);
	root->left->left = newtNode(8);
	root->left->right = newtNode(-4);
	root->right->right = newtNode(-4);
	printf("%d", getMinimumDepth(root));
	getch();
}
