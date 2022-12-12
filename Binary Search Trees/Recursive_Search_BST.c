#include <stdint.h>
#include <stdlib.h>
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

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

struct Node *search_BST(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search_BST(root->left, key);
    }
    else
    {
        return search_BST(root->right, key);
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

    inOrder(p);
    printf("\n");
    printf("%d", isBST(p));
    printf("\n");

    // struct Node *n = search_BST(p, 4);
    // if(n != NULL){
    //     printf("Found: %d", n->data);
    // }
    // else{
    //     printf("Element Not Found");
    // }

    printf("%d", minValue(p));

    return 0;
}