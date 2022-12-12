#include<stdint.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int main(){
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(11);
    struct Node *p4 = createNode(31);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    

    return 0;
}