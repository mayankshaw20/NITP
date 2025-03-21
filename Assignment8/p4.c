// 4. Write a program in C to check if a String is a palindrome using a StaACK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX];
    char stack[MAX];
    int top = -1;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    // str[strcspn(str, "\n")] = 0; //for Removing the newline character
    int len = strlen(str);
    int mid = len / 2;

    // Push the first half of the string onto the stack
    for (int i = 0; i < mid; i++) {
        stack[++top] = str[i];
    }

    // Start comparing from the middle (for odd length, skip the middle character)
    for (int i = (len % 2 == 0) ? mid : mid + 1; i < len; i++) {
        if (stack[top--] != str[i]) {
            printf("'%s' is not a palindrome.\n", str);
            return 0; // Not a palindrome
        }
    }

    printf("'%s' is a palindrome.\n", str);
    return 0; // Is a palindrome
}