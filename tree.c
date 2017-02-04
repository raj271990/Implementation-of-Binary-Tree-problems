#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

// structure of tree node

struct Node {
       struct Node *left;
       int val;
       struct Node *right;
};

// structure of stack

struct sNode {
    struct Node *val;
    struct sNode *next;   
};

//  function of stack
push(struct sNode **ptop, struct Node *current) {
    struct sNode *oldtop = *ptop;
    *ptop = (struct sNode *)malloc(sizeof(struct sNode));
    (*ptop)->val = current;
    (*ptop)->next = oldtop;
    oldtop = NULL;
}


// Pop function of stack

struct Node * pop(struct sNode **ptop) {
    struct Node *temp = (*ptop)->val;
    *ptop = (*ptop)->next;
    return temp;
}


// Check if stack is empty

bool isStackEmpty(struct sNode **ptop) {
    return ((*ptop) == NULL);
}

struct QNode {
   struct Node *val;
   struct QNode *next;    
} *front = NULL, *rear = NULL;

struct QNode * newQNode(struct Node *x) {
    struct QNode *y = (struct QNode *)malloc(sizeof(struct QNode));
    y->val = x;
    y->next = NULL;
    return y;
}

struct Node * newNode(int i) {
   struct Node *x = (struct Node *)malloc(sizeof(struct Node));
   x->left = NULL;
   x->val = i;
   x->right = NULL;
   return x;
}

//Enqueue

enqueue(struct Node *x) {
    if(rear == NULL) {
        rear = newQNode(x);
        front = rear;
    }
    else {
        struct QNode *oldrear = rear;
        rear = newQNode(x);
        oldrear->next = rear;
        oldrear = NULL; 
    }
}

// Dequeue 

struct Node * dequeue() {
    if(front != NULL) {
        struct QNode *oldfront = front;
        front = front->next;
        if(front == NULL) rear = NULL;
        struct Node *x = oldfront->val;
        free(oldfront);
        return x;
    }
    return NULL;
}

// print integer value

print(int val) {
    printf("%d ", val);
}

// print new Line

newLine() {
    printf("\n");
}


// Inorder Traversal


inorder(struct Node *root) {
    if(root == NULL) return;
    inorder(root->left);
    print(root->val);
    inorder(root->right);
}


// Calculate maximum of two integer values 


int maxOf(int i, int j) {
    if(i>=j) return i;
    return j;
}

// Calculate height of tree


int height(struct Node *root) {
    if(root == NULL) return 0;
    return ((height(root->left), height(root->right)) + 1);
}


// Level Order Traversal

levelOrder(struct Node *root) {
    enqueue(root);
    struct Node *x;
    while((x = dequeue()) != NULL) {
        print(x->val);
        if(x->left != NULL) enqueue(x->left);
        if(x->right != NULL) enqueue(x->right);
    }
}


// Size of tree

int size(struct Node *root) {
    if(root == NULL) return 0;
    return (size(root->left) + size(root->right) + 1);
}

// Number of leaves

int numberOfLeaves(struct Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return(numberOfLeaves(root->left) + numberOfLeaves(root->right));
}


// print all leaves

printLeaves(struct Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        print(root->val);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

// Sum of leaves

int sumOfLeaves(struct Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->val;
    return(sumOfLeaves(root->left) + sumOfLeaves(root->right));
}


// Print Given Level of tree

printLevel(struct Node *root, int level) {
    if(root == NULL) return;
    if(level == 0) print(root->val);
    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
}


// Level order Line By Line

levelOrderByLine(struct Node *root) {
    int h = height(root);
    int level;
    for(level = 0; level<h; level++){
        printLevel(root, level);
        newLine();
    }
}


// Check if trees are identical

bool areIdentical(struct Node *r1, struct Node *r2) {
	if(r1 == NULL && r2 == NULL) return true;
	if(r1 != NULL && r2 != NULL) {
		return(areIdentical(r1->left, r2->left) && areIdentical(r1->right, r2->right) && r1->val == r2->val);
	}
	return false;
}

// Delete a tree


deleteTree(struct Node **atroot) {
	if(*atroot == NULL) return;
	deleteTree(&((*atroot)->left));
	deleteTree(&((*atroot)->right));
	free(*atroot);
	*atroot=NULL;
}


// Tree Delete in another way
pvtdelTree(struct Node *root) {
	if(root == NULL) return;
	pvtdelTree(root->left);
	pvtdelTree(root->right);
	free(root);
}

delTree(struct Node **toroot) {
	pvtdelTree(*toroot);
	*toroot = NULL;
}

// Convert a tree to its mirror tree

swap(struct Node **p1, struct Node **p2) {
	struct Node *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

mirror(struct Node *root) {
	if(root == NULL) return; // Base condition
	mirror(root->left);
	mirror(root->right);
	swap(&root->left,&root->right);
}


// Level order in spiral form

printLevelSpiral(struct Node *root, int level, bool lt_to_rt) {
	if(root == NULL) return;
	if(level == 0) {
		print(root->val);
		return;
	}
	if(lt_to_rt) {
		printLevelSpiral(root->left, level-1, lt_to_rt);
		printLevelSpiral(root->right, level-1, lt_to_rt);
		return;
	}
	printLevelSpiral(root->right, level-1, lt_to_rt);
	printLevelSpiral(root->left, level-1, lt_to_rt);
}


levelOrderSpiral(struct Node *root) {
	bool lt_to_rt = true;
	int l, h;
	h = height(root);
	for(l = 0; l < h; l++) {
		printLevelSpiral(root, l, lt_to_rt);
		newLine();
		lt_to_rt = !lt_to_rt;
	}
}


// Root to Leaf Paths - o(n)

printPaths(int paths[], int level) {
	int i;
	for(i=0;i<=level;i++) print(paths[i]);
}

dfs(struct Node *root, int level, int paths[]) {
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL) {
		paths[level] = root->val;
		printPaths(paths,level);
		newLine();
	}
	paths[level] = root->val;
	dfs(root->left, level+1, paths);
	dfs(root->right, level+1, paths);
}

rootToLeafPaths(struct Node *root) {
	int h = height(root);
	int paths[h], level = 0;
	dfs(root, level, paths);
}


// Inorder traversal without recursion

inorderWR(struct Node *root) {
    struct Node *current = root;
    struct sNode *top = NULL;
    while(current != NULL || !isStackEmpty(&top)) {
        if(current != NULL) {
            push(&top, current);
            current = current->left;
        }
        else {
             current = pop(&top);
             print(current->val);
             current = current ->right;
        }
    }
}

// Check tree is a BST or not

bool isBST(struct Node *root) {
    if(root == NULL) return true;
    if(root->left !=NULL && root->right != NULL) return(root->val > root->left->val  && root->val < root->right->val && isBST(root->left) && isBST(root->right));
    if(root->right != NULL) return(root->val < root->right->val && isBST(root->right));
    if(root->left != NULL) return(root->val > root->left->val && isBST(root->left));
    return true;
}


// maximum width

bool less(int a, int b) {
    return (a<b);
}

int countNodesAtLevel(struct Node *root, int level) {
    if(root == NULL) return 0;
    if(level == 0) return 1;
    return (countNodesAtLevel(root->left, level-1) + countNodesAtLevel(root->right, level-1));
}

int maxWidth(struct Node *root) {
    int currentWidth =0, maxWidth = 0;
    int level;
    int h = height(root);
    for(level = 0; level < h; level++) {
        currentWidth = countNodesAtLevel(root, level);
        if(less(maxWidth,currentWidth)) maxWidth = currentWidth;
    }
    return maxWidth;
}



// Left View
printLeftNodeAtLevel(struct Node *root, int level, bool *done) {
    if(root == NULL) return;
    if(level == 0) {
        print(root->val);
        *done = true;
        return;
    }
    printLeftNodeAtLevel(root->left, level-1, done);
    if(!(*done)) printLeftNodeAtLevel(root->right, level-1,done);
}

printLeftView(struct Node *root) {
    int h = height(root);
    int level;
    bool isPrinted;
    for(level = 0; level < h; level++) {
        isPrinted = false;
        printLeftNodeAtLevel(root, level, &isPrinted);
    }
}


// Check if tree is height balanaced

bool areAllLeavesAtMaxlevelLeaf(struct Node *root,int level, int max_level_leaf) {
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL) {
		return(level == max_level_leaf);
	}
	return (areAllLeavesAtMaxlevelLeaf(root->left, level+1, max_level_leaf) &&
		   areAllLeavesAtMaxlevelLeaf(root->right, level+1, max_level_leaf));
}


bool isHTBalanced(struct Node *root) {
	int max_level_leaf = height(root)-1;
	int level = 0;
	return(areAllLeavesAtMaxlevelLeaf(root,level,max_level_leaf));
}



// Get Level of a node

int getNodeLevel(struct Node *root, int level, int key) {
	if(root == NULL) return -1;
	if(root->val == key) return level;
	int l1 = getNodeLevel(root->left, level+1, key);
	if(l1 != -1) return l1;
	return(getNodeLevel(root->right, level+1, key));
}


// Print all nodes at distance k from the root

allNodesAtDist(int k, struct Node *root) {
	if(root == NULL) return;
	if(k == 0) print(root->val);
	allNodesAtDist(k-1, root->left);
	allNodesAtDist(k-1, root->right);
}


// root to leaf path sum equal to a given number
/*
bool hasRootLeafpathSum(int k, struct Node *root) {
	if(root == NULL) return false;
	if(root->left == NULL && root->right == NULL) return (root->val == k);
	if(hasRootLeafpathSum(k-root->val, root->left)) return true;
	return hasRootLeafpathSum(k-root->val, root->right);
} */


//root to leaf path sum equal to a given number and also print that path

printPath(int path[], int level) {
	int i;
	for(i=0;i<=level;i++) print(path[i]);
	newLine();
}

bool hasRootLeafpathSum(int k, struct Node *root, int level, int path[]) {
	if(root == NULL) return false;
	path[level] = root->val;
	//if leaf
	if(root->left == NULL && root->right == NULL) {
		if(root->val == k) {
			printPath(path,level);
			return true;
		}
	}
	if(hasRootLeafpathSum(k-root->val, root->left, level+1, path)) return true;
	return hasRootLeafpathSum(k-root->val, root->right, level+1, path);
}


// Print all paths with sum equal to a given number


allPathsWithSum(int k, struct Node *root, int level, int path[]) {
	if(root == NULL) return;
	path[level] = root->val;
	if(root->left == NULL && root->right == NULL && root->val == k) {
		printPath(path, level);
		return;
	}
	allPathsWithSum(k-root->val,root->left,level+1,path);
	allPathsWithSum(k-root->val,root->right,level+1,path);
}


// LCA in a BST


// Helper function

bool equals(int a, int b) {
	return a==b;
}

int LCA(struct Node *root, int n1, int n2) {
	if(equals(root->val,n1) || equals(root->val,n2)) return root->val;
	if(less(n1,root->val) && less(root->val, n2)) return root->val;
	if(less(n2,root->val)) return (LCA(root->left,n1,n2));
	if(less(root->val,n1)) return (LCA(root->right,n1,n2));
}

// Search for a key - recursive

bool searchKey(struct Node *root, int key) {
	if(root == NULL) return false;
	if(root->val == key) return true;
	if(searchKey(root->left, key)) return true;
	return searchKey(root->right, key);
}

// Search for a key - Iterative


// LCA in a Binary Tree - There could be a better approach than one written below


int LCA_BT(struct Node *root, int n1, int n2) {
	if(root == NULL) return -1;
	if(n1 == root->val || n2 == root->val) return root->val;
	bool b1 = searchKey(root->left, n1);
	bool b2 = searchKey(root->left, n2);
	if(b1 && b2) return LCA_BT(root->left, n1, n2);
	if(!b1 && !b2) return LCA_BT(root->right, n1, n2);
	return root->val;
}


// Ancestors of a node in a tree

printRevPath(int path[], int n) {
	int i;
	for(i = n; i >= 0; i--) print(path[i]);
}

ancestors(struct Node *root,int level, int path[], int key) {
	if(root == NULL) return;
	if(root->val == key) {
		printRevPath(path,level-1);
		return;
	}
	path[level] = root->val;
	ancestors(root->left, level+1, path, key);
	ancestors(root->right, level+1, path, key);
}

// Preorder without recursion


int valueOf(struct Node *current) {
    if(current == NULL) return 0;
    return current->val; 
}


// Convert to sum tree
to_Sum_Tree(struct Node *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    to_Sum_Tree(root->left);
    to_Sum_Tree(root->right);
    root->val = valueOf(root->left) + valueOf(root->right);
}



// Maximum in a binary tree


int gt_of(int m1, int m2) {
    if(m1 >= m2) return m1;
    return m2;
}


int max(struct Node *root) {
    if(root == NULL) return INT_MIN;
    int max_of_subtrees = gt_of(max(root->left), max(root->right));
    return (gt_of(max_of_subtrees, root->val));
}


// Minimum in a binary tree

int sm_of(int m1, int m2) {
    if(m1 <= m2) return m1;
    return m2;
}


int min(struct Node *root) {
    if(root == NULL) return INT_MAX;
    int min_of_subtrees = sm_of(min(root->left), min(root->right));
    return (sm_of(min_of_subtrees, root->val));
}



// Minimum depth of a binary tree

int lesser_of(int d1, int d2) {
    if(d1<=d2) return d1;
    return d2;
}

int min_depth(struct Node *root) {
    if(root == NULL) return -1;
    return lesser_of(min_depth(root->left), min_depth(root->right)) + 1;
} 


// check if binar tree is full or not

bool isFullBT(struct Node *root) {
    if(root == NULL) return true;
    if(isFullBT(root->left) && isFullBT(root->right)) {
        return !(root->left == NULL ^ root->right == NULL);
    }
    return false;
}


// Client


int main() {
    struct Node *root;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    //root->left->right = newNode(5);
    //root->right->left = newNode(25);
     
    struct Node *root2;
    root2 = NULL;//newNode(5);
    //root2->left = NULL; //newNode(7);
    //root2->right = NULL;//newNode(2);
    //root2->right->left = NULL;
    //root2->right->right = newNode(4);
    //levelOrder(root2);
    //inorder(root);
    //delTree(&root);
    //newLine();
    //inorder(root);
    //print(height(root));
    //newLine();
    //levelOrder(root);
    //print(size(root));
    //print(numberOfLeaves(root));
    //printLeaves(root);
    //print(sumOfLeaves(root));
    //levelOrderByLine(root);
    //printf("Are identical = %d", areIdentical(root,root2));
    //levelOrder(root);
    //mirror(root);
    //newLine();
    //front = rear = NULL;
    //levelOrder(root);
    //inorder(root);
    //levelOrderSpiral(root);
    //rootToLeafPaths(root2);
    //inorderWR(root);
    //printf("Is BST = %d", isBST(root2));
    //print(maxWidth(root));
    //printLeftView(root);
    //printf("Is Height Balanced = %d",isHTBalanced(root));
    //print(getNodeLevel(root,0,7));                       
    //allNodesAtDist(0,root);
    //printf("Has root to Leaf path sum = %d", hasRootLeafpathSum(11, root));
    //int h = height(root);
    //int path[h];
    //allPathsWithSum(8, root, 0, path);
    //printf("Is Key present = %d", searchKey(root, 17));
    //print(LCA_BT(root,0,25));
    //int h = height(root);
    //print(h);
    //int path[h];
    //ancestors(root,0,path,6);
    //to_Sum_Tree(root);
    //levelOrder(root);
    //print(min_depth(root));
    printf("%x",isFullBT(root2));
        getch();
}
