#include <stdio.h>
#include <stdlib.h>

void merge(int l, int mid, int r, int *arr) {
    int n = r - l + 1;
    int temp[n];
    int idx = 0;

    int i = l;
    int j = mid+1;

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            temp[idx++] = arr[i++];
        else
            temp[idx++] = arr[j++];
    }

    while (i <= mid)
        temp[idx++] = arr[i++];
    while (j <= r)
        temp[idx++] = arr[j++];

    for (int i=0; i<n; i++) 
        arr[i+l] = temp[i];
}

void sort(int l, int r, int *arr) {
    if (l < r) {
        int m = (r + l) / 2;
        sort(l, m, arr);
        sort(m+1, r, arr);
        merge(l, m, r, arr);
    }
}

void worstData(int l, int r, int *arr) {
    if (l >= r)
        return;

    int m = (l + r) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[n1], b[n2];

    // Split even and odd indices
    for (int i = 0; i < r - l + 1; i++) {
        if (i % 2 == 0)
            a[i / 2] = arr[l + i];
        else
            b[i / 2] = arr[l + i];
    }

    // Recursively split subarrays
    worstData(0, n1 - 1, a);
    worstData(0, n2 - 1, b);

    // Copy back into original array
    for (int i = 0; i < n1; i++)
        arr[l + i] = a[i];
    for (int i = 0; i < n2; i++)
        arr[l + n1 + i] = b[i];
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

    // Create sorted 1 to n
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    // Generate worst-case input using your worstData
    worstData(0, n - 1, arr);

    printf("Worst-case input for merge sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sort the array
    sort(0, n - 1, arr);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

