// 7. Write a program in C to find the minimum absolute difference between any two
// elements of an unsorted array.
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int minAbsDifference(int arr[], int n) {
    if (n < 2) return -1; // Not enough elements to find a difference
    selectionSort(arr, n);
    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 1; i < n - 1; i++) {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff < minDiff) minDiff = diff;
    }
    return minDiff;
}

int main() {
    int arr[] = {3, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = minAbsDifference(arr, n);
    if (result != -1)
        printf("Minimum absolute difference is %d\n", result);
    else
        printf("Array must contain at least two elements.\n");
    return 0;
}