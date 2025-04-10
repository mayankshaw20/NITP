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

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = createNode(data);
            break;
        } else {
            queue[rear++] = current->left;
        }
        if (current->right == NULL) {
            current->right = createNode(data);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}

int countNonLeafNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    for (int i = 1; i <= 7; i++) insert(&root, i);
    printf("Number of non-leaf nodes: %d\n", countNonLeafNodes(root));
    return 0;
}