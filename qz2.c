#include <stdio.h>

void circular_shift(int A[], int n, int k) {
    k = k % n; // Handle k larger than n for efficiency

    // Reverse the entire array
    for (int i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }

    // Reverse the first k elements
    for (int i = 0; i < k / 2; i++) {
        int temp = A[i];
        A[i] = A[k - i - 1];
        A[k - i - 1] = temp;
    }

    // Reverse the remaining elements (n-k)
    for (int i = k; i < (n + k) / 2; i++) {
        int temp = A[i];
        A[i] = A[n - i - 1 + k];
        A[n - i - 1 + k] = temp;
    }
}

int main() {
    int A[] = {5, 15, 29, 35, 42};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 2;

    circular_shift(A, n, k);

    printf("Shifted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
