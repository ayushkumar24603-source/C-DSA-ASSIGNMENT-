/*
Q1. Stack implementation using an array
Operations: PUSH, POP, PEEK, DISPLAY
Handles Stack Overflow and Stack Underflow.

Time Complexity:
PUSH    : O(1)
POP     : O(1)
PEEK    : O(1)
DISPLAY : O(n)

Space Complexity:
Stack storage: O(n), where n is the fixed capacity.
*/

#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Stack is full.\n");
        return;
    }

    stack[++top] = x;
    printf("%d pushed into the stack.\n", x);
}

void pop(void) {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("%d popped from the stack.\n", stack[top--]);
}

void peek(void) {
    if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void display(void) {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
