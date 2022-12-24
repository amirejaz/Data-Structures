#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
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

int PUSH(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack is full/Overflow and %d cannot pushed into stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        
    };
}

int POP(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is Underflow and cannot popped from stack\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));


    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    PUSH(sp, 65);
    PUSH(sp, 6);
    PUSH(sp, 5);
    PUSH(sp, 3);
    PUSH(sp, 7);
    PUSH(sp, 8);
    PUSH(sp, 9);
    PUSH(sp, 10);

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("\n");
    
    printf("Popped %d from the stack\n", POP(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", POP(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", POP(sp)); // --> Last in first out!

    return 0;

}