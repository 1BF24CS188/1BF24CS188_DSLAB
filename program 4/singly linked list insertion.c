#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node*head= NULL;
void createlist(int n){
    struct node* newnode, *temp;
    int data,i;
    if(n<=0){
        printf("Nodes number must be positive.\n");
        return;
    }
    head=NULL;
    temp=NULL;
    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode== NULL){
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("Node is created.\n");
}
void insertAtBeginning(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("Node is inserted at the beginning.\n");
}
void insertAtEnd(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
    }printf("Node is inserted at the end.\n");
    }
    void insertAtPosition(int data,int pos){
        int i;
        struct node* newnode,*temp=head;
        if(pos<0){
            printf("Invalid position.\n");
            return;
        }
        else if(pos==0){
            insertAtBeginning(data);
            return;
        }
        else{
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            for(i=1;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            if(temp==NULL){
                printf("Position out of range.\n");
                free(newnode);
            }
            else{
                newnode->next=temp->next;
                temp->next=newnode;
            }
            }
        }
    void display(){
        struct node* temp=head;
        if(head==NULL){
            printf("List is empty.\n");
            return;
        }
        else{
            printf("\nLinked list:");
            while(temp!=NULL){
                printf("%d ->",temp->data);
                temp=temp->next;
            }
        }
        printf("NULL\n");
    }
    int main(){
        int n,data,pos,ch;
        while(1){
            printf("\n1.create linked list\n2.insert at beginning\n3.insert at end\n4.insert at any position\n5.display\n6.exit\n");
            printf("Enter your choice:");
            scanf("%d",&ch);
            switch(ch){
                case 1:
                printf("Enter number of nodes:\n");
                scanf("%d",&n);
                createlist(n);
                break;

                case 2:
                printf("Enter data to insert:\n");
                scanf("%d",&data);
                insertAtBeginning(data);
                break;

                case 3:
                printf("Enter data to insert:\n");
                scanf("%d",&data);
                insertAtEnd(data);
                break;

                case 4:
                printf("Enter data to insert and the position to insert:\n");
                scanf("%d%d",&data,&pos);
                insertAtPosition(data,pos);
                break;
                
                case 5:
                display();
                break;

                case 6:
                printf("Exiting the program.\n");
                exit(0);

                default:
                printf("Invalid choice,\n");
                break;
            }
        }
        return 0;
    }



