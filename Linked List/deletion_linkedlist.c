#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void Linkedlist(struct Node *ptr){
    while(ptr->next != NULL){
        
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1 Delete a node at first
struct Node *deletion_atFirst(struct Node *head){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = head;
    head = head->next;
    free(ptr);
    return(head);
};

// Case 2: Delete a node in between
struct Node *deletion_atIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
    
};

// Case 3: Delete the last node 
struct Node *deletion_atEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

// Case 4: Delete a given value in linked list
struct Node *deletion_atValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);

    }
    
    return head;
    
};




int main(){
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *first = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 38;
    head->next = first;

    first->data = 26;
    first->next = second;

    second->data = 9;
    second->next = third;
    
    third->data = 7;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = NULL;

    printf("The elements of Linked list are: \n");
    Linkedlist(head);

    printf("\n");
    // head = deletion_atFirst(head); 

    // head = deletion_atIndex(head, 2);
    
    // head = deletion_atEnd(head);

    head = deletion_atValue(head, 7);

    
    printf("The elements of Linked list after deletion are: \n");
    Linkedlist(head);
}