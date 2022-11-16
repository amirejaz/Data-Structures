#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *doublyLinkedlist_Traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Elements in forwarding Doubly LinkedList is: %d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr != NULL);
    printf("\n");
};

struct Node *doubly_reverseTraversal(struct Node *head, struct Node *last)
{
    struct Node *ptr = last;
    while (ptr != head)
    {
        printf("Elements in reverse Doubly LinkedList is: %d\n", ptr->data);
        ptr = ptr->prev;
    };

    printf("\n");
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 4;
    head->next = first;

    first->prev = head;
    first->data = 7;
    first->next = second;

    second->prev = first;
    second->data = 37;
    second->next = third;

    third->prev = second;
    third->data = 26;
    third->next = last;

    last->prev = third;
    last->data = 43;
    last->next = NULL;

    head = doublyLinkedlist_Traversal(head);

    // doubly_reverseTraversal(head, last);
}