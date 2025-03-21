// 1. Write a program in C to find the intersection point of two Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (!headA || !headB) return NULL;
    struct Node *a = headA, *b = headB;
    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);
    
    struct Node* headB = createNode(4);
    headB->next = createNode(5);
    
    struct Node* intersection = createNode(6);
    intersection->next = createNode(7);
    
    headA->next->next->next = intersection; // 3 -> 6 -> 7
    headB->next->next = intersection;       // 5 -> 6 -> 7

    printf("Linked List A: ");
    printList(headA);
    printf("Linked List B: ");
    printList(headB);

    struct Node* intersectionNode = getIntersectionNode(headA, headB);
    printf("Intersection at node with data: %d\n", intersectionNode ? intersectionNode->data : -1);

    return 0;
}