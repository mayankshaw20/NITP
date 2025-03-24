// 7. Write a program in C to implement a Queue using two Stacks.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top, items[MAX];
} Stack;

typedef struct {
    Stack* s1, *s2;
} Queue;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack* s, int value) {
    if (s->top < MAX - 1) s->items[++s->top] = value;
}

int pop(Stack* s) {
    return (s->top >= 0) ? s->items[s->top--] : -1;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = createStack();
    q->s2 = createStack();
    return q;
}

void enqueue(Queue* q, int value) {
    push(q->s1, value);
}

int dequeue(Queue* q) {
    if (q->s2->top == -1) {
        while (q->s1->top >= 0) push(q->s2, pop(q->s1));
    }
    return pop(q->s2);
}

void display(Queue* q) {
    for (int i = q->s2->top; i >= 0; i--) printf("%d ", q->s2->items[i]);
    for (int i = 0; i <= q->s1->top; i++) printf("%d ", q->s1->items[i]);
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10); enqueue(q, 20); enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    enqueue(q, 40); enqueue(q, 50);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    free(q->s1); free(q->s2); free(q);
    return 0;
}