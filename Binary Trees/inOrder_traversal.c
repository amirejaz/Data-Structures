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

void inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(0);
    struct Node *p4 = createNode(1);
    struct Node *p5 = createNode(5);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p5;

    inOrder(p);
    return 0;
}