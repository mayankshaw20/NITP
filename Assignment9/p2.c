// 2. Write a C program to implement Binary search on a sorted array


#include <stdio.h>
#include <stdlib.h>

int Binary_search(int *arr, int *size, int *target) {
    int start = 0;
    int end = *size - 1; // Use dereferenced size

    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate mid inside the loop

        if (arr[mid] > *target) {
            end = mid - 1; // Move end pointer
        } else if (arr[mid] < *target) {
            start = mid + 1; // Move start pointer
        } else {
            return mid; // Return the index
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target: ");
    scanf("%d", &target);

    int index = Binary_search(arr, &size, &target); // Pass addresses of size and target
    if (index == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Desired result found at the index: %d\n", index);
    }
    return 0;
}