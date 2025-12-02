#include<stdio.h>
#include<stdlib.h> 

struct node {
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;

struct node* createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insert(struct node* head,int data){
    struct node* newNode=createNode(data);
    if(head==NULL){
        return newNode;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void displayList(struct node *head){
    if(head == NULL){
        printf("empty\n");
    } else{
        struct node* temp = head;
        while(temp != NULL){
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int concatenate(struct node *head1, struct node *head2){
    struct node *temp = head1;
    if(head1==NULL){
        return head2;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
int reverse(struct node *head){
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int sort(struct node *head){
    if(head==NULL){
        return head;
    }
    struct node *i, *j;
    int temp;
    for(i = head; i->next!= NULL ; i=i->next){
        for(j = i->next; j != NULL; j=j->next){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }return head;
}

int main(){
    struct node* list1=NULL;
    struct node* list2=NULL;
    int choice,val,n;
    while(1){
        printf("1. Insert at list 1\n");
        printf("2. Insert at list 2\n");
        printf("3. Display list 1\n");
        printf("4. Display list 2\n");
        printf("5. Concatenate lists\n");
        printf("6. Reverse list\n");
        printf("7. Sort list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter number of elements to insert:");
                scanf("%d",&n);
                printf("Enter %d elements:\n",n);
                for(int i=0;i<n;i++){
                    scanf("%d",&val);
                    list1=insert(list1,val);
                }
                break;
            case 2:
                printf("Enter number of elements to insert:");
                scanf("%d",&n);
                printf("Enter %d elements:\n",n);
                for(int i=0;i<n;i++){
                    scanf("%d",&val);
                    list2=insert(list2,val);
                }
                break;
            case 3:
            printf("List1:");
                displayList(list1);
                break;
            case 4:
            printf("List2:");
                displayList(list2);
                break;
            case 5:
                list1=concatenate(list1, list2);
                displayList(list1);
                break;
            case 6:
                list1=reverse(list1);
                displayList(list1);
                break;
            case 7:
                list1=sort(list1);
                displayList(list1);
                break;
            case 8:
            printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


