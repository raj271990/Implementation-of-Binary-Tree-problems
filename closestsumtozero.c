#include <stdio.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>

//helper functions

void swap(int a[], int i, int j) {
     int swap = a[i];
     a[i] = a[j];
     a[j] = swap;
}

bool less(int a, int b) {
     if(a < b) {
          return true;
     }
     return false;
}

// private partition routine
int partition(int a[], int i, int j) {
    // we will maintain invariant p. The elements before this location would be smaller than or equal to pivot element [we will be choosing first element as the pivot element
    // to parttion the array] and those after would be greater
    int pivot = a[i],p =i,t;
    for(t = i+1; t <= j; t++) {
            if(less(a[t],pivot)) {
                          p = p + 1;
                          swap(a, p, t);
            }
    }
    // Take pivot to index of p
    swap(a, i, p);
    return p;
}

// quickSort routine
quickSort(int a[], int i, int j) {
     // Base condition
     if(j<=i) return;
     //Inductive step
     int p = partition(a, i, j);
     quickSort(a, i, p-1);
     quickSort(a, p+1, j);
}


findClosestSumToZero(int a[], int n) {
    quickSort(a, 0, n-1);
    //int r;
    //for(r=0;r<n;r++) printf("%d ", a[r]);
    int i=0, j=n-1, num1, num2, sum=INT_MAX, tempSum;
    while(i<j) {
        tempSum = abs(a[i] + a[j]);
        if(tempSum < sum) {
            sum = tempSum;
            num1 = a[i];
            num2 = a[j];
        }
        if(abs(a[i]) > abs(a[j])) i++;
        else j--;
    }
    printf("%d %d\n", num1, num2);
}

int main() {
	int numTestCases, n, i;
	scanf("%d", &numTestCases);
	while(numTestCases--) {
	    scanf("%d", &n);
	    int a[n];
	    for(i=0;i<n;i++) {
	        scanf("%d", &a[i]);
	    }
	    findClosestSumToZero(a,n);
	}
	return 0;
}
