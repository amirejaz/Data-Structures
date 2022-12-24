#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct stack *next;
};

struct Node *Linkedlist_Traversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top){
    if(top == NULL){
        printf("Stack underflow");
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node *top){
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
};

struct Node *PUSH(struct Node *top, int data){
    if(isFull(top)){
        printf("Stack is overflow");
    }
    else{
        struct Node *n = (struct Node *) malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
};

int POP(struct Node **top){
    if(isEmpty(*top)){
        printf("Stack is Underflow");
    }
    else{
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
        
    }
};

int PEEK(struct Node *top, int pos){
    struct Node *ptr = top;
    for (int i = 0; (i < pos-1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
    
}

int stackTOP(struct Node *top){
    struct Node *ptr = top;
    return ptr->data;
}

int stackBOTTOM(struct Node *top){
    struct Node *ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
        return ptr->data;
}

void main(){
    struct Node *top = NULL;
    top = PUSH(top, 65);
    top = PUSH(top, 8);
    top = PUSH(top, 6);
    top = PUSH(top, 13);
    top = PUSH(top, 7);


    printf("The value at position 2 is %d\n",PEEK(top, 2));

    printf("The element at the top of Stack is %d\n", stackTOP(top));
    printf("Element at the bottom is: %d\n", stackBOTTOM(top));

    int element = POP(&top);
    printf("Element popped is: %d\n", element);

    Linkedlist_Traversal(top);

    return 0;
}
