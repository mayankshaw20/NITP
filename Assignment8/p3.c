// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// // Stack structure
// struct Stack {
//     int items[MAX];
//     int top;
// };

// // Function to initialize the stack
// void initStack(struct Stack* s) {
//     s->top = -1;
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack* s) {
//     return s->top == -1;
// }

// // Function to push an element onto the stack
// void push(struct Stack* s, int item) {
//     if (s->top < MAX - 1) {
//         s->items[++(s->top)] = item;
//     }
// }

// // Function to pop an element from the stack
// int pop(struct Stack* s) {
//     if (!isEmpty(s)) {
//         return s->items[(s->top)--];
//     }
//     return -1; // Stack underflow
// }

// // Function to find the next greater element for each element in the array
// void nextGreaterElement(int arr[], int n) {
//     int result[n]; // Array to store the result
//     struct Stack s;
//     initStack(&s);

//     for (int i = 0; i < n; i++) {
//         // While stack is not empty and the current element is greater than the element at the index stored at the top of the stack
//         while (!isEmpty(&s) && arr[i] > arr[s.items[s.top]]) {
//             result[pop(&s)] = arr[i]; // Pop index and set the result
//         }
//         push(&s, i); // Push current index onto the stack
//     }

//     // For remaining elements in the stack, there is no greater element
//     while (!isEmpty(&s)) {
//         result[pop(&s)] = -1; // Set result to -1
//     }

//     // Print the result
//     printf("Next greater elements: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int arr[] = {6, 8, 0, 1, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     nextGreaterElement(arr, n);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, arr[MAX], next[MAX], stack[MAX], top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i])
            top--;

        next[i] = (top == -1) ? -1 : stack[top];

        stack[++top] = arr[i];
    }

    printf("Next greater elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", next[i]);
    return 0;
}