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


// structure of q data

struct qData {
    struct tNode *tNode_ptr;
    int tNode_level;
};



// Structure of queue Node
struct qNode {
	struct qData qNodeData;
	struct qNode *next;
};

// create new queue node

struct qNode * newqNode(struct qData qNodeData) {
	struct qNode *x = (struct qNode *)malloc(sizeof(struct qNode));
	x->qNodeData = qNodeData;
	x->next = NULL;
	return x;
}


// Enqueue 

enqueue(struct qData qNodeData, struct qNode **frontref, struct qNode **rearref) {
	if((*rearref) == NULL) {
        (*rearref) = newqNode(qNodeData);
        *frontref = *rearref;
    }
    else {
        (*rearref)->next = newqNode(qNodeData);
        (*rearref) = (*rearref)->next;
    }
}


// Dequeue - returns pointer to tree node
struct qData dequeue(struct qNode **frontref, struct qNode **rearref) {
	// get the value of front node
	struct qData qNodeData = (*frontref)->qNodeData;
	// remove the front member from the queue
	(*frontref) = (*frontref)->next;
	// Check if no member in queue...if thats the case, there there wouldnt be any member // at the back of te queue as well
	if((*frontref) == NULL) (*rearref) = NULL;
	// return the stored value pointed earlier by front
	return qNodeData;
}

// check if queue empty
bool isEmpty(struct qNode **frontref) {
   // printf("frontref = %d\n",(*frontref)->tptr->val);
	return((*frontref) == NULL);
}

int maxOf(int a, int b) {
    if(a>b) return a;
    return b;
}

int height(struct tNode *root) {
    if(root==NULL) return 0;
    return maxOf(height(root->left), height(root->right)) + 1;
}

// Support for main function prepared till here



bfs_modified(struct tNode *root, int low, int high) {
    struct qNode *front = NULL, *rear = NULL;
    struct qData qNodeData;
    struct tNode *curr_tNode_ptr = NULL;
    int curr_tNode_level = 1, prev_tNode_level= curr_tNode_level;
    
    qNodeData.tNode_ptr = root;
    qNodeData.tNode_level = curr_tNode_level;
    
    enqueue(qNodeData, &front, &rear);
    
    while(!isEmpty(&front)) {
        qNodeData = dequeue(&front, &rear);
        
        curr_tNode_ptr = qNodeData.tNode_ptr;
        curr_tNode_level = qNodeData.tNode_level;
        
        if(curr_tNode_level < low) {
            prev_tNode_level = curr_tNode_level;
        }
        else if(curr_tNode_level <= high) {
             if(curr_tNode_level > prev_tNode_level) {
                 prev_tNode_level = curr_tNode_level;
                 printf("\n");
             }
            printf("%d ", curr_tNode_ptr->val);
        }
        else return;
        
        if(curr_tNode_ptr->left != NULL) {
            qNodeData.tNode_ptr = curr_tNode_ptr->left;
            qNodeData.tNode_level = curr_tNode_level + 1;
            enqueue(qNodeData, &front, &rear);
        }
        
        if(curr_tNode_ptr->right != NULL) {
            qNodeData.tNode_ptr = curr_tNode_ptr->right;
            qNodeData.tNode_level = curr_tNode_level + 1;
            enqueue(qNodeData, &front, &rear);
        }
    }
}


// Client exposed function to print nodes between two levels 
print_Nodes_Btw_Low_High(struct tNode *root, int low, int high) {
    if(root == NULL) {
        printf("There is no tree");
        return;
    }
    int h = height(root);
    if(low>=1 && low<=high && high<=h) bfs_modified(root, low, high);
    else {
        printf("Bounds not proper");
        return;
    }
}


// Function to print


// client

int main() {
	// create a binary tree
	struct tNode *root = new newtNode(20);
	root->left = newtNode(8);
	root->right = newtNode(22);
	root->left->left = newtNode(4);
	root->left->right = newtNode(12);
	root->left->right->left = newtNode(10);
	root->left->right->right = newtNode(14);
	// pass the tree for doing level order traversal
	int low = 1, high = 4;
	print_Nodes_Btw_Low_High(root, low, high);
	getch();
}
