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
    printf("l: %d r: %d\n", l, r);
    if (l < r) {
        int m = (r + l) / 2;
        sort(l, m, arr);
        sort(m+1, r, arr);
        merge(l, m, r, arr);
    }
}

void worstData(int l, int r, int *arr) {
    if (l < r) {
        int m = (l + r) / 2;
        int n1=(m-beg)+1, n2=(end-mid);
        int a[n1], b[n2];

        for (int i=0; i<n1; i++) {
            a[i] = arr[2 * i];
        }

        for (int i=0; i<n2; i++) {
            b[i] = arr[2 * i + 1];
        }

        worst(a, l, mid);
        worst(a, mid+1, r);
    }

    for (int i=0; i<n1; i++) {
        arr[i+l] = a[i];
    }
    for (int i=0; i<n2; i++) {
        arr[i+mid+1] = b[i];
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

    sort(0, n-1, arr);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

