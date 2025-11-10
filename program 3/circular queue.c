#include <stdio.h>
#define N 5 // Size of the circular queue

int queue[N];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void enqueue(int x) {
    if ((rear + 1) % N == front) {
        printf("Queue Overflow! The queue is full.\n");
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("%d inserted into the queue.\n", x);
    } 
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("%d inserted into the queue.\n", x);
    }
}

// Function to delete an element from the circular queue
void dequeue() {
    int item;
    if (front == -1 && rear == -1) {
        printf("Queue Underflow! The queue is empty.\n");
    } 
    else if (front == rear) {
        item = queue[front];
        front = rear = -1;
        printf("Deleted element: %d\n", item);
    } 
    else {
        item = queue[front];
        front = (front + 1) % N;
        printf("Deleted element: %d\n", item);
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } 
    else {
        int i = front;
        printf("Queue elements are: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int ch, x;

    while (1) {
        printf("\n------ CIRCULAR QUEUE MENU ------\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}