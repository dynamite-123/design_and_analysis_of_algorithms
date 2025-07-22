#include <stdio.h>
#include <stdlib.h>

int search(int n, int arr[], int target) {
    int count = 0;

    for (int i=0; i<n; i++) {
        count++;
        if (arr[i] == target) {
            break;
        }
    }

    return count;
}

void plotter() {
    

    FILE *fbest = fopen("sequential_best.txt", "w");
    FILE *fworst = fopen("sequential_worst.txt", "w");

    int n = 0;
    int target = 1;

    for (int n=1; n<100000; n += 100) {

        int *arr = malloc(sizeof(int) * n);

        for (int i=0; i<n; i++) {
            arr[i] = 0;
        }

        //worst case
        arr[n-1] = 1;
        int wcount = search(n, arr, target);

        //best case
        arr[0] = 1;
        int bcount = search(n, arr, target);

        fprintf(fbest, "%d\t%d\n", n, bcount);
        fprintf(fworst, "%d\t%d\n", n, wcount);
    }
}

void main() {
    plotter();
}
