#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* push(struct node *top, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    return top;
}

struct node* pop(struct node *top) {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    struct node *temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
    return top;
}

void displayStack(struct node *top) {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct node *temp = top;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(struct node **front, struct node **rear, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(*rear == NULL) {
        *front = *rear = newnode;
        return;
    }

    (*rear)->next = newnode;
    *rear = newnode;
}

void dequeue(struct node **front, struct node **rear) {
    if(*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = *front;
    printf("Dequeued element: %d\n", temp->data);

    *front = (*front)->next;

    if(*front == NULL)
        *rear = NULL;

    free(temp);
}

void displayQueue(struct node *front) {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    struct node *temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL; 
    struct node *front = NULL, *rear = NULL; 

    int choice, val, n;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Push multiple values (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue multiple values (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("How many values to push? ");
            scanf("%d", &n);
            printf("Enter %d values:\n", n);
            for(int i = 0; i < n; i++) {
                scanf("%d", &val);
                top = push(top, val);
            }
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            displayStack(top);
            break;

        case 4:
            printf("How many values to enqueue? ");
            scanf("%d", &n);
            printf("Enter %d values:\n", n);
            for(int i = 0; i < n; i++) {
                scanf("%d", &val);
                enqueue(&front, &rear, val);
            }
            break;

        case 5:
            dequeue(&front, &rear);
            break;

        case 6:
            displayQueue(front);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}