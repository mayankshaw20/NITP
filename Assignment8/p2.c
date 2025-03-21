#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in a linked list
int detectLoop(struct Node* head) {
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;               // Move slow pointer by 1
        fastPtr = fastPtr->next->next;         // Move fast pointer by 2

        // If slow and fast pointers meet, there is a loop
        if (slowPtr == fastPtr) {
            return 1; // Loop found
        }
    }
    return 0; // No loop
}

// Function to print the linked list (for testing purposes)
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

// Main function to test the loop detection
int main() {
    // Create a linked list with a loop for testing
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
    // Creating a loop for testing: 4 -> 2
    head->next->next->next->next = head->next;

    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
