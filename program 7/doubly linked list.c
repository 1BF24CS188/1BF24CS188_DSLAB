#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createList(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertStart(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertleftofPosition(int data, int position) {
    if (position <= 1) {
        insertStart(data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        insertEnd(data);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;

    temp->prev = newNode;
}
void deleteByValue(int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted value %d\n", value);
}

void deletePosition(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    if (position == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, pos,n;

    while (1) {
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Create doubly linked list\n");
        printf("2. Insert at Start\n");
        printf("3. Insert at End\n");
        printf("4. Insert at left of Position\n");
        printf("5. Delete by Value\n");
        printf("6. Delete by Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("How many values?");
            scanf("%d", &n);
            for(int i=0;i<n;i++){
                printf("Enter value %d:",i+1);
                scanf("%d",&val);
                createList(val);
            }
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertStart(val);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(val);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertleftofPosition(val, pos);
            break;

        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteByValue(val);
            break;

        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;

        case 7:
            display();
            break;

        case 8:
        printf("Exiting");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
