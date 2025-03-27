// 6. Implement a program in C to find the Kth smallest element in an unsorted array using
// any sorting algorithm.
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int kthSmallest(int arr[], int n, int k) {
    insertionSort(arr, n);
    return arr[k - 1];
}

int main() {
    int arr[] = {12, 3, 5, 7, 19}; 
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    printf("The %dth smallest element is %d\n", k, kthSmallest(arr, n, k));
    return 0;
}
