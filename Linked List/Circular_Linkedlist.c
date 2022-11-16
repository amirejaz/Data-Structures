#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * circularLinkedlist_Traversal(struct Node *head){
    struct Node *ptr = head;

    do{
        printf("Elements in Circular LinkedList is: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
};

struct Node *Insertion_atFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data = data;

    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

void main(){
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *first = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 4;
    head->next = first;

    first->data = 7;
    first->next = second;

    second->data = 37;
    second->next = third;

    third->data = 26;
    third->next = fourth;

    fourth->data = 43;
    fourth->next = head;

    head = circularLinkedlist_Traversal(head);

    printf("\nCircular Linked list after insertion \n");
    head = Insertion_atFirst(head, 78);
    head = circularLinkedlist_Traversal(head);

}