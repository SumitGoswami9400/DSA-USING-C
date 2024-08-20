/*#include<stdio.h>
#include<stdlib.h>

#define max 50
void push(char[],char,int*);
char pop(char[],int*);
int prec(char);
char infix_to_postfix(char[]);

int main(){
    char infix[max]={'(','A','+','B',')','*','(','C','-','D',')',')','\0'};
    char postfix[max],stack[max],x,ch,y,z;
    int top = -1,i=0,j=0;
    push(stack,'(',&top);
    while(infix[i] != '\0'){
        if(ch =='('){
            push(stack,ch,&top);
            break;
        }
        else if(ch == 65 && ch<=90 || ch>=97 && ch<=122){
            postfix[j]=ch;
            j++;
            break;
        }
        else if(ch == '+' || ch == '-' || ch== '*'||ch=='/'||ch=='%'){
            while(prec(ch)<= prec(stack[top])){
            y = pop(stack,&top);
            postfix[j++] = y;
            }
            push(stack,ch,&top);
        }
        else if(ch==')'){
            while(y==pop(stack,&top)!='('){
                postfix[j] = y;
                j++;
            }
        }
        z = pop(stack,&top);
    }
    for(i=0;i<max-1;i++){
        printf("%d",postfix[i]);
    }
    return 0;
}

int prec(char x){
    if(x == '^'){
        return 5;
    }
    else if(x == '*' || x== '/' || x == '%'){
        return 4;
    }
    else if(x=='+' || x=='-'){
        return 3;
    }
    else{
        return 2;
    }
}

void push(char stack[],char ch,int *top){
    int i;
    for(i=0;i<max-1;i++){
        if(ch == '('){
            (*top)++;
            stack[*top]=ch;
        }
    }

}
char pop(char stack[],int *top){
    int x;
    x=stack[*top];
    (*top)--;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '^')
        return 4;
    if(ch == '*' || ch=='/' || ch =='%')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch == '%' || ch == '^') 
        return 1;
    else
        return 0;
}


char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "A*B-C+D%E+G^H-I/J";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPR_SIZE 100

// Function to return precedence of operators
int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '%':
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
// Function to check if the scanned character 
// is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^' || ch == '%');
}
  
// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[MAX_EXPR_SIZE];
    int top = -1;
  
    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        
        // If the scanned character is operand
        // add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        
        // if the scanned character is '('
        // push it in the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        
        // if the scanned character is ')'
        // pop the stack and add it to the 
        // output string until empty or '(' found
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }
        
        // If the scanned character is an operator
        // push it in the stack
        else if (isOperator(infix[i])) {
            while (top > -1
                   && precedence(stack[top])
                          >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
  
    // Pop all remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}
  
// Driver code
int main()
{
    char infix[MAX_EXPR_SIZE] = "(A*B-C)+(D%E)+G^H-I/J";
    
    // Function call
    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}

