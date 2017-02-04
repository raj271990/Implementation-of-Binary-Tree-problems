// Reshuffle array
reshuffle(int arr1[], int k, int l, int arr2[], int i, int j, int p) {
    int l1 = k-1;
    int l2 = k;
    while(l2 <= l) {
        
    }
}


//  constrcut tree

struct tNode * consTree(int in[]), int i, int j, int lv[], int k, int l, struct tNode *root) {
    if(i > j) return NULL;
    int p = indexOf(lv[k], in, i, j);
    // construct root
    root = newtNode(in[p]);
    // resuffle level order array to have level order traversal of left subtree on left side of array and level order
    // traversal of right subtree on the right side of the array
    reshuffle(lv, k+1, l, in[], i, j, p);
    // construct left subtree
    root->left = consTree(in, i, p-1, lv, k+1, k+p-i);
    // construct right subtree
    root->right = consTree(in, p+1, j, lv, k+p-i+1, l);
    // return constructed tree
    return root;
}
