// 5. Implement a function in C to find the minimum and maximum values in a Binary Search Tree.
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

struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int findMin(struct Node* root) {
    if (!root) return -1; // Indicate that the tree is empty
    while (root->left) root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (!root) return -1; // Indicate that the tree is empty
    while (root->right) root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    printf("Minimum value in the BST: %d\n", findMin(root));
    printf("Maximum value in the BST: %d\n", findMax(root));

    return 0;
}