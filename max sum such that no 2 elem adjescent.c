#include <stdio.h>

int maxOf(int a, int b) {
    if(a>=b) return a;
    return b;
}

int maxSum(int a[], int i, int j, int c[]) {
    if(i>j) return 0;
    if(i==j) return a[i];
    if(c[j] == 0) {
        c[j] = maxOf(maxSum(a,i,j-1,c), (maxSum(a,i,j-2,c) + a[j]));
    }
    return c[j];
}

int main() {
    int numTestCases,n, i;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        int a[n],c[n];
        scanf("%d", &n);
        for(i=0;i<n;i++) {
            scanf("%d", &a[i]);
            c[i] = 0;
        }
        printf("%d\n", maxSum(a,0,n-1,c));
    }
	return 0;
}
