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
        void deleteAtFirst(){
            struct node* temp;
            if(head==NULL){
                printf("List is empty.\n");
                return;
            }
            temp=head;
            head=head->next;
            free(temp);
            printf("Node is deleted from beginning.\n");
        }
        void deleteAtEnd(){
            struct node* temp,*prev;
            if(head==NULL){
                printf("List is empty.\n");
                return;
            }
            if(head->next==NULL){
                free(head);
                head=NULL;
                printf("Node is deleted from end.\n");
                return;
            }
            temp=head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            free(temp);
            printf("Node is deleted from end.\n");
        }
        void deleteByValue(int value){
            struct node* temp=head;
            struct node* prev=NULL;
            if(head==NULL){
                printf("List is empty.\n");
                return;
            }
            if(head->data==value){
                head=head->next;
                free(temp);
                printf("Node deleted is:%d\n",temp->data);
                return;
            }
            while(temp!=NULL && temp->data!=value){
                prev=temp;
                temp=temp->next;
            }
            if(temp==NULL){
                printf("Value not found\n");
                return;
            }
            prev->next=temp->next;
            printf("Node deleted is:%d\n",temp->data);
            free(temp);
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
            printf("\n1.create linked list\n2.insert at beginning\n3.insert at end\n4.insert at any position\n5.delete at beginning\n6. delete at end\n7.delete by value\n8.display\n9.exit\n");
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
                deleteAtFirst();
                break;

                case 6:
                deleteAtEnd();
                break;

                case 7:
                printf("Enter value to delete:\n");
                scanf("%d",&data);
                deleteByValue(data);
                break;

                case 8:
                display();
                break;

                case 9:
                printf("Exiting the program.\n");
                exit(0);

                default:
                printf("Invalid choice,\n");
                break;
            }
        }
        return 0;
    }



