#include <stdio.h>
#include <stdlib.h>

int search(int l, int r, int arr[], int target) {
    int count = 0;
    
    int mid = (l + r) / 2;

    if ((l > r) || (arr[mid] == target)){
        return 1; 
    } else if (target > arr[mid]) {
        return 1 + search(mid+1, r, arr, target); 
    } else {
        return 1 + search(l, mid-1, arr, target); 
    }
}

void plotter() {
    FILE *fbest = fopen("binary_best.txt", "w");
    FILE *fworst = fopen("binary_worst.txt", "w");

    int n = 0;

    for (int n=1; n<100000; n += 100) {

        int *arr = malloc(sizeof(int) * n);

        for (int i=0; i<n; i++) {
            arr[i] = 0;
        }

        //worst case
        int wcount = search(0, n-1, arr, 1);

        //best case
        int bcount = search(0, n-1, arr, 0);

        fprintf(fbest, "%d\t%d\n", n, bcount);
        fprintf(fworst, "%d\t%d\n", n, wcount);
    }
}

void main() {
    plotter();
}
