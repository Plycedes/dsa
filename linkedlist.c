#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* Node;

void printList(Node* headref){
    Node temp = (Node)malloc(sizeof(Node));
    temp = (*headref);
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void pushFront(Node* headref, int newData){
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = (*headref);
    (*headref) = newNode;
}

void pushBack(Node* endref, int newData){
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = newData;
    (*endref)->next = newNode;
    newNode->next = NULL;
}

void pushAt(Node* headref, int newData, int index){
    Node newNode = (Node)malloc(sizeof(Node));
    Node temp = (Node)malloc(sizeof(Node));
    int count = 0;
    temp = (*headref);
    newNode->data = newData;
    while(count != index-1){
        temp = temp->next;
        count++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteFront(Node* headref){
    Node temp = (Node)malloc(sizeof(Node));
    temp = (*headref);
    (*headref) = temp->next;
    free(temp);
}

void deleteBack(Node* headref, Node* endref){
    Node temp = (Node)malloc(sizeof(Node));
    Node prev = (Node)malloc(sizeof(Node));
    temp = (*headref);
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    (*endref) = prev;
    free(temp);
}

void deleteAt(Node* headref, int index){
    Node temp = (Node)malloc(sizeof(Node));
    Node prev = (Node)malloc(sizeof(Node));
    int count = 0;
    temp = (*headref);
    while(count != index){
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    free(temp);
}

int main(){
    Node head = (Node)malloc(sizeof(Node));
    Node end = (Node)malloc(sizeof(Node));    

    head->data = 10;
    end->data = 20;

    head->next = end;
    end->next = NULL;

    pushFront(&head, 30);
    pushBack(&end, 40);
    pushFront(&head, 50);
    pushBack(&end, 60);
    pushAt(&head, 70, 3);
    deleteFront(&head);
    deleteBack(&head, &end);
    pushBack(&end, 80);
    deleteAt(&head, 3);
    printList(&head);
}