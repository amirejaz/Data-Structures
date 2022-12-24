#include<stdio.h>
#include<stdlib.h>

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
        return 0;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char POP(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow");
        return 0;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int multi_parenthesis_match(char *exp){
    struct stack *sp;
    sp->size = 80;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char popped_ch;

    for(int i=0; exp[i] == '\0'; i++){
        if(exp[i] == '(' || exp[i]== '{' || exp[i] == '['){
            PUSH(sp, exp[i]);
        }
        else if(exp[i] == ')' || exp[i]== '}' || exp[i] == ']'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                popped_ch = POP(sp);
                if(!match(popped_ch, exp[i])){
                    return 1;
                }
                
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *exp = "{62}*(263&)";
    if(multi_parenthesis_match(exp)){
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }
    return 0;
}
