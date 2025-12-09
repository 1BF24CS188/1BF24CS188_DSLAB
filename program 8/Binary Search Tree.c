#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* CreateNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* Insert(struct Node* root, int value){
    if(root == NULL){
        return CreateNode(value);
    }
    if(value < root->data){
        root->left = Insert(root->left, value);
    } else if(value > root->data){
        root->right = Insert(root->right, value);
    }
    return root;
}
void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}
void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void display(struct Node *root){
    printf("BINARY SEARCH TREE\n");
    printf("Inorder Transversal");
    inorder(root);
    printf("\nPreorder Transversal");
    preorder(root);
    printf("\nPostorder Transversal");
    postorder(root);
    printf("\n");
}
int main(){
    struct Node* root=NULL;
    int choice,value;
    while(1){
        printf("1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Display\n6.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("How many values to insert:");
                int n;
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("Enter value %d:",i+1);
                    scanf("%d",&value);
                    root=Insert(root,value);
                }
                break;
                
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                display(root);
                break;
            case 6:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}