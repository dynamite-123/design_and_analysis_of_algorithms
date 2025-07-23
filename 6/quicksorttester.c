#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int l, int r, int *arr) {
    int p = arr[l];
    int i=l+1, j=r;

    while (i <= j) {
        while (arr[i] > p)
            i++;
        while (arr[j] < p)
            j--;
        if (i<j)
            swap(&arr[i], &arr[j]);

        return j;
    }
}

void quicksort(int l, int r, int *arr) {
    if (l < r) {
        int split = partition(l, r, arr);
        quicksort(l, split-1, arr);
        quicksort(split+1, r, arr);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(0, n-1, arr);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

