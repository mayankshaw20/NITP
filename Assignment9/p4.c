// 4. Write a program in C to implement Selection sort and display the sorted linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void selectionSort(struct Node* head) {
    struct Node *current, *minNode, *prevMin;
    for (current = head; current; current = current->next) {
        minNode = current; prevMin = NULL;
        for (struct Node *next = current->next; next; next = next->next) {
            if (next->data < minNode->data) { minNode = next; prevMin = current; }
        }
        if (minNode != current) {
            int temp = current->data; current->data = minNode->data; minNode->data = temp;
        }
    }
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data; new_node->next = (*head_ref); (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node) { printf("%d ", node->data); node = node->next; }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 45); push(&head, 25); push(&head, 62); push(&head, 21); push(&head, 100);
    printf("Unsorted Linked List: "); printList(head);
    selectionSort(head);
    printf("Sorted Linked List: "); printList(head);
    return 0;
}