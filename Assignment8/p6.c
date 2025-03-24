// Write a program in C to implement a Circular Queue using an Array.
// Write a program in C to implement a Circular Queue using an Array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX], front, rear;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = -1;
    return q;
}

int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)){ printf("Queue is full\n"); return;}
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    printf("element enqueued : %d \n",value);
    q->items[q->rear] = value;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) { printf("Queue is empty\n");return -1;}
    int item = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX;
    return item;
}

void display(CircularQueue* q) {
    if (isEmpty(q)) return;
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int main() {
    CircularQueue* q = createQueue();
    enqueue(q, 10); enqueue(q, 20); enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40); enqueue(q, 50); enqueue(q, 60);
    enqueue(q, 40); enqueue(q, 50); enqueue(q, 60);
    display(q);
    free(q);
    return 0;
}
