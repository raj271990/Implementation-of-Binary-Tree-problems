#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>


// Sructure of tree node
struct tNode {
	struct tNode *left;
	int val;
	struct tNode *right;
};

// Structure of queue Node
struct qNode {
	struct tNode *tptr;
	struct qNode *next;
};

// create new tree node

struct tNode * newtNode(int nodeData) {
	struct tNode *x = (struct tNode *)malloc(sizeof(struct tNode));
	x->left = NULL;
	x->val = nodeData;
	x->right = NULL;
	return x;
}

//Create new queue node
struct qNode * newqNode(struct tNode *current) {
	struct qNode *rear = (struct qNode *)malloc(sizeof(struct qNode));
	rear->tptr = current;
	rear->next = NULL;
	return rear;
}

// Enqueue

enqueue(struct tNode *current, struct qNode **frontref, struct qNode **rearref) {
	// if inserting as first node in queue
	if((*frontref) == NULL) {
		*rearref = newqNode(current);
		*frontref = *rearref;
	}
	else {
		struct qNode *oldrear = *rearref;
		*rearref =newqNode(current);
		oldrear->next = *rearref;
	}
}

// Dequeue - returns pointer to tree node
struct tNode * dequeue(struct qNode **frontref, struct qNode **rearref) {
	// get the value of front node
	struct tNode *x = (*frontref)->tptr;
	// remove the front member from the queue
	(*frontref) = (*frontref)->next;
	// Check if no member in queue...if thats the case, there there wouldnt be any member // at the back of te queue as well
	if((*frontref) == NULL) (*rearref) = NULL;
	// return the stored value pointed earlier by front
	return x;
}

// check if queue empty
bool isEmpty(struct qNode **frontref) {
   // printf("frontref = %d\n",(*frontref)->tptr->val);
	return((*frontref) == NULL);
}


// Print nodes between two levels
printNodesBtLevel(struct tNode *root, int low, int high) {
     struct qNode *front = NULL, *rear = NULL;
     struct tNode *current_tNode;
     int level = 1;
     
     // Create marker node
     struct tNode *marker = newtNode(INT_MIN);
     
     // Enqueue root with a marker node
     enqueue(root, &front, &rear);

     enqueue(marker, &front, &rear);

     
     while(!isEmpty(&front)) {
          current_tNode = dequeue(&front, &rear);
          // Check if dequeued node is marker. If yes, print new line and increase level, as nodes from now till end of
          // next level will be printed in new line.Chcck if queue is empty or incremented level is greater than high. If yes, 
          // break. If no, push the marker node to mark the end of next level
          if(current_tNode == marker) {
              printf("\n");
              level++;
              if(isEmpty(&front) || level > high) break;
              enqueue(marker, &front, &rear);
          }
          else {
              if(level >= low) printf("%d ", current_tNode->val);
              
              // Enqueue left and right child
              if(current_tNode->left != NULL) enqueue(current_tNode->left, &front, &rear);
              if(current_tNode->right != NULL) enqueue(current_tNode->right, &front, &rear);
          }
     }
     
}


// client

int main() {
	// create a binary tree
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);
	// pass the tree for doing level order traversal
	printNodesBtLevel(root,1,2);
	getch();
	return 0;
}





