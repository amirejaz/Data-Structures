#include<stdio.h>
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

struct Node *insert(struct Node *root, int key){
    struct Node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data == key){
            printf("Cannot insert %d because it already exists in BST", key);
            return; 
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node *new = createNode(key);
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

int main(){
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p2->right = p4;

    insert(p, 8);
    printf("%d",p->right->right->right->data);

    return 0;
}