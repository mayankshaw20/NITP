#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    int f = 1;
    while (n > 0) f *= n--;
    return f;
}

int npr(int n, int r) {
    return fact(n) / fact(n - r);
}

int** allocate_memory(int n, int size) {
    int **res = (int**)calloc(size, sizeof(int*));
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < npr(n, i); j++) {
            res[idx++] = (int*)calloc(i, sizeof(int));
        }
    }
    return res;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void permutations(int** res, int* arr, int n, int idx, int k, int* count) {
    if (idx == k) {
        for (int j = 0; j < k; j++) res[*count][j] = arr[j];
        (*count)++;
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(arr, idx, i);
        permutations(res, arr, n, idx + 1, k, count);
        swap(arr, idx, i);
    }
}

void generate_permutations(int* arr, int n, int** res) {
    int count = 0;
    for (int k = 1; k <= n; k++) {
        permutations(res, arr, n, 0, k, &count);
    }
}

int find_max_divisible(int** res, int n, int flag) {
    int size = 0, max = -1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < npr(n, i); k++) {
            int num = 0;
            for (int j = 0; j < i; j++) num = num * 10 + res[size + k][j];
            if (num % flag == 0 && num > max) max = num;
        }
        size += npr(n, i);
    }
    return max;
}

void free_memory(int** res, int size) {
    for (int i = 0; i < size; i++) free(res[i]);
    free(res);
}

int main() {
    int arr[] = {8, 1, 7, 6, 0}, n = 5, size = 0;
    for (int i = 1; i <= n; i++) size += npr(n, i);

    int **res = allocate_memory(n, size);
    generate_permutations(arr, n, res);
    
    int max_ele = find_max_divisible(res, n, 3);
    printf("Max divisible by 3: %d\n", max_ele);

    free_memory(res, size);
    return 0;
}