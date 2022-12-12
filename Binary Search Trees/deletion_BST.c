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

struct Node *inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

struct Node *inOrderPredecessor(struct Node *root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct Node *deletion_BST(struct Node *root, int value){
    struct Node *inPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left = deletion_BST(root->left, value);
    }
    else if(value > root->data){
        root->right = deletion_BST(root->right, value);
    }
    else{
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deletion_BST(root->left, inPre->data);
    }
    return root;
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
    p1->right = p4;

    inOrder(p);
    printf("\n");
    deletion_BST(p, 4);
    printf("\n");
    inOrder(p);

}