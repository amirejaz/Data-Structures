#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void LinkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;

    head = (struct Node *) malloc(sizeof(struct Node));
    first = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));

    head->data = 28;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 83;
    second->next = NULL;

    LinkedlistTraversal(head);
    
}
