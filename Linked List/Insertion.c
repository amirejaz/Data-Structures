#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1 : Insert the element at beginning of linked list
struct Node *Insertion_atFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

// Case 2 : Insert the element at any Index of linked list
struct Node *Insertion_atIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
};

// Case 3 : Insert the element at the end of linked list
struct Node *Insertion_atEnd(struct Node *head, int data)
{
    struct Node *element_toEnd = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    element_toEnd->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    };

    p->next = element_toEnd;
    element_toEnd->next = NULL;

    return head;
};

// Case 4 : Insert the node in linked list
struct Node *Insertion_Node(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *node_to_insert = (struct Node *)malloc(sizeof(struct Node));
    node_to_insert->data = data;
    node_to_insert->next = prevNode->next;

    prevNode->next = node_to_insert;

    return head;
};

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 28;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 83;
    second->next = NULL;

    LinkedlistTraversal(head);

    // head = Insertion_atFirst(head, 78);
    printf("\n");

    // printf("Linked list after inserting first element: \n");
    printf("Linked list after inserting: \n");

    // Insertion_atIndex(head, 66, 2);

    // head = Insertion_Node(head, first, 53);

    head = Insertion_atEnd(head, 82);
    LinkedlistTraversal(head);

    return 0;
}
