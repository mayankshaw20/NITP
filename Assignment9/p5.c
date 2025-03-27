// 5. Write a program in C to implement Insertion sort and display the sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertionSort(struct Node** head_ref) {
    struct Node *sorted = NULL, *current = *head_ref;
    while (current) {
        struct Node *next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted; sorted = current;
        } else {
            struct Node *temp = sorted;
            while (temp->next && temp->next->data < current->data) temp = temp->next;
            current->next = temp->next; temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
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
    push(&head, 14); push(&head, 20); push(&head, 124); push(&head, 52); push(&head, 110);
    printf("Unsorted Linked List: "); printList(head);
    insertionSort(&head);
    printf("Sorted Linked List: "); printList(head);
    return 0;
}