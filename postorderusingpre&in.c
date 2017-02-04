// print post order, given inorder and preorder
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>

int indexOf(int key, int arr[], int m, int n) {
    int i;
    for(i=m;i<=n;i++) {
        if(arr[i] == key) return i;
    }
    return INT_MIN;
}

postorder(int in[], int i, int j, int pre[], int k, int l) {
    if(i>j) return;
    int p = indexOf(pre[k], in, i, j);
    postorder(in, i, p-1, pre, k+1, k+p-i);
    postorder(in, p+1, j, pre, k+p-i+1, l);
    printf("%d ", in[p]);
}

main() {
    int in[] = {4,2,5,1,3,6};
    int pre[] = {1,2,4,5,3,6};
    postorder(in, 0, 5, pre, 0,5);
    getch();
}
