#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void PUSH(struct stack *ptr, char val){
    if(isFull(ptr)){
        printf("stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val; 
    }
}

char POP(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top]; 
        ptr->top--;
        return val;
    }
}

int stackTOP(struct stack *ptr){
    return ptr->arr[ptr->top];
}


int precedence(char data){
    if(data == '*' || data =='/'){
        return 3;
    }
    else if(data == '+' || data == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char data){
    if(data == '+' || data == '-' || data == '*' || data == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 60;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; 
    int j = 0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTOP(sp))){
                PUSH(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = POP(sp);
                j++;
            }
        }

    } 
    while(!isEmpty(sp)){
        postfix[j] = POP(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *infix = "((A + (B*C)+B)-((C+E)/D))-C";
    printf("The expression in postfix is: %s", infixToPostfix(infix));
    return 0;
}