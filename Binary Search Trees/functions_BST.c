#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct Node *ascendingOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

struct Node *decsendingOrder(struct Node *root)
{
    if (root != NULL)
    {
        decsendingOrder(root->right);
        printf(" %d ", root->data);
        decsendingOrder(root->left);
    }
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    ascendingOrder(p);
    printf("\n");

    printf("\n");
    decsendingOrder(p);
}