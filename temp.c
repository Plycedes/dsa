#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node* Node;

Node newNode(int newData){
    Node newnode = (Node)malloc(sizeof(Node));
    newnode->data = newData;
    newnode->left = newnode->right = NULL;
    //printf("%d ", newData);
    return newnode;
}

Node insert(Node node, int newData){
    if(node == NULL){
        return newNode(newData);
    }
    if(newData < node->data){
        node->left = insert(node->left, newData);
    }
    else if(newData > node->data){
        node->right = insert(node->right, newData);
    }
    return node;
}

void inorder(Node node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    printf("%d\n", node->data);
    inorder(node->right);
}

int main(){
    Node root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 28);
    insert (root, 45);
    insert(root, 16);

    inorder(root);
    return 0;
}