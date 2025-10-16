#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push(){
    int n,x;
    printf("How many elements do you want to push\n");
    scanf("%d",&n);
    if(n>(N-top-1)){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    printf("Elements are pushed into the stack\n");
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is popped out of the stack\n",stack[top]);
        top--;
    }
}
void peek(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Top element is: %d\n",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Stack elements from top to bottom are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    int ch;
    do{
        printf("Enter your choice: 1.push 2.pop 3.peek 4.display 0.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 0:printf("Exiting the program\n");
            break;
            default:printf("Invalid choice\n");

        }
    }while(ch!=0);
    return 0;
}
