/*
Q2. Circular Queue implementation using an array
Operations: ENQUEUE, DEQUEUE, FRONT, DISPLAY
Correctly distinguishes between a full queue and an empty queue.

Time Complexity:
ENQUEUE : O(1)
DEQUEUE : O(1)
FRONT   : O(1)
DISPLAY : O(n)

Space Complexity:
Queue storage: O(n), where n is the fixed capacity.

Why circular queue uses memory better:
In a simple linear queue, positions freed at the beginning may remain
unused when REAR reaches the last index. A circular queue reuses those
freed positions by wrapping REAR back to index 0.

In a linear queue, this can cause a false overflow even when there are
unused positions at the beginning. A circular queue avoids this problem.
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty(void) {
    return front == -1;
}

int isFull(void) {
    return (rear + 1) % MAX == front;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("%d enqueued into the queue.\n", x);
}

void dequeue(void) {
    int removed;

    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    removed = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("%d dequeued from the queue.\n", removed);
}

void showFront(void) {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display(void) {
    int i;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                showFront();
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
