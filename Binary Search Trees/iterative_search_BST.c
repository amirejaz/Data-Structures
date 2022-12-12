#include<stdint.h>
#include<stdlib.h>
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

int isBST(struct Node *root){
    static struct Node *previous_node = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(previous_node != NULL && root->data <= previous_node->data){
            return 0;
        }
        previous_node = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct Node *iterative_Search(struct Node *root, int key){
    while(root != NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
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
    printf("%d", isBST(p));
    printf("\n");

    struct Node *n = iterative_Search(p, 4);
    if( n!=NULL){
        printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}