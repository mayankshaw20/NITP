// 4.	Write a program in C to implement a Binary Search 
// Tree with functions for insertion, searching, and deletion of nodes.
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

struct Node* search(struct Node* root, int data) {
    if (!root || root->data == data) return root;
    return data < root->data ? search(root->left, data) : search(root->right, data);
}

struct Node* minValueNode(struct Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (!root) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice == 2) {
            printf("Enter value to search: ");
            scanf("%d", &value);
            printf("Value %d %s in the BST.\n", value, search(root, value) ? "found" : "not found");
        } else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value %d deleted from the BST.\n", value);
        } else if (choice == 4) {
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}