// 4. Write a program in C to implement Bucket sort and display the sorted array of
// integers.

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void insertionSort(int arr[], int n) {
    for (int i = 1, key, j; i < n; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--) arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    int bucketCount = n / BUCKET_SIZE + 1, **buckets = malloc(bucketCount * sizeof(int *)), *bucketSizes = calloc(bucketCount, sizeof(int));
    for (int i = 0; i < bucketCount; i++) buckets[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        if (bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }
    for (int i = 0, index = 0; i < bucketCount; i++) {
        if (bucketSizes[i]) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) arr[index++] = buckets[i][j];
        }
    }
    for (int i = 0; i < bucketCount; i++) free(buckets[i]);
    free(buckets); free(bucketSizes);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51, 49, 50, 38}, n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n"); printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array: \n"); printArray(arr, n);
    return 0;
}