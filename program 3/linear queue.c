#include<stdio.h>
#define N 5

int queue[N];
int front=-1, rear=-1;

void enqueue(int x){
    if(rear == N-1){
        printf("Queue Overflow!\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        printf("%d inserted\n", x);
    }
    else{
        rear++;
        queue[rear] = x;
        printf("%d inserted\n", x);
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow!\n");
    }
    else if(front == rear){
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int ch, val;

    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter value: ");
                    scanf("%d", &val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Program End\n");
                    return 0;
            default: printf("Invalid choice\n");
                    break;
        }
    }
}