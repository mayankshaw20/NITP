// 6.	Write a program in C to convert the Binary Tree into Binary Search Tree?
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderCollect(struct Node* root, int* arr, int* index) {
    if (root) {
        inorderCollect(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorderCollect(root->right, arr, index);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void inorderReplace(struct Node* root, int* arr, int* index) {
    if (root) {
        inorderReplace(root->left, arr, index);
        root->data = arr[(*index)++];
        inorderReplace(root->right, arr, index);
    }
}

void convertToBST(struct Node* root) {
    if (!root) return;
    int size = 0, *arr = (int*)malloc(100 * sizeof(int)); // Assuming a max of 100 nodes
    inorderCollect(root, arr, &size);
    qsort(arr, size, sizeof(int), compare);
    int index = 0;
    inorderReplace(root, arr, &index);
    free(arr);
}

void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(15);
    root->left->left = createNode(5);
    root->left->right = createNode(20);

    printf("Original tree (inorder):\n");
    inorderTraversal(root);
    printf("\n");

    convertToBST(root);

    printf("Converted BST (inorder):\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}