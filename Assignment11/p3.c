// 3.	Write a program in C to find the minimum depth of binary tree?
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

int minDepth(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(5);
    printf("Minimum depth of the binary tree: %d\n", minDepth(root));
    return 0;
}