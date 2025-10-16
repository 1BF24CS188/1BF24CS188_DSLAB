#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 100
int stack[N];
int top=-1;
void push(char c){
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=c;
    return;
}
char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
char peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}
int is_operator(char c){
    return(c=='^'||c=='+'||c=='-'||c=='/'||c=='*'||c=='%');
}
int precedence(char c){
    switch(c){
        case '^': return 3;
        case '*': 
        case '%': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}
void infixtopostfix(char *infix, char *postfix){
    int k=0;
    char symbol;
    push('(');
    int len=strlen(infix);
    infix[len]=')';
    infix[len+1]='\0';
    for(int i=0;i<=len;i++){
        symbol=infix[i];
        if(isalnum(symbol)){
            postfix[k++]=symbol;
        }
        else if(symbol=='('){
            push('(');
        }
        else if(is_operator(symbol)){
            while(top!=0 && precedence(peek())>=precedence(symbol)){
                postfix[k++]=pop();
            }
            push(symbol);
        }
        else if(symbol==')'){
            while(top!=-1 && peek()!='('){
                postfix[k++]=pop();
            }pop();
        }
    }
    postfix[k]='\0';
}
int main(){
    char infix[N],postfix[N];
    printf("Enter an infix expression\n");
    scanf("%s",&infix);
    infixtopostfix(infix,postfix);
    printf("The postfix expression is:%s\n",postfix);
    return 0;
}