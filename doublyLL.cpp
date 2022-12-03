#include <iostream>

using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
};

void printFD(Node* head){    
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

void printBD(Node* end){
    while(end!=NULL){
        cout<<end->data<<endl;
        end=end->prev;
    }
}

void pushFront(Node** headref, int newData){
    Node* newNode = new Node();
    newNode->data=newData;
    newNode->prev=NULL;
    newNode->next=(*headref);
    (*headref)->prev=newNode;
    (*headref)=newNode;
}

void pushBack(Node** endref, int newData){
    Node* newNode = new Node();
    Node* last = *endref;
    newNode->data = newData;
    while(last->next!=NULL){
        last=last->next;
    }
    newNode->next= NULL;
    newNode->prev= last;
    last->next=newNode;
    (*endref) = newNode;
}

void pushAt(Node** headref, int newdata, int key){
    Node* newNode = new Node();
    Node* head = (*headref);
    Node* prev = NULL;
    newNode->data=newdata;
    int count = 1;
    while(count!=key){
        prev = head;
        head = head->next;
        count++;
    }
    prev->next=newNode;
    newNode->prev=prev;
    newNode->next=head;
    head->prev=newNode;
}

int main(){

    Node* head = new Node();
    Node* middle = new Node();
    Node* end = new Node();

    head->prev=NULL;
    head->next=middle;

    middle->prev=head;
    middle->next=end;    

    end->prev=middle;
    end->next=NULL;

    head->data=10;
    middle->data=20;
    end->data=30;

    pushFront(&head, 40);
    pushBack(&end, 50);
    pushBack(&end, 60);
    pushAt(&head, 70, 2);

    //printFD(head); 
    printBD(end);

    return 0;
}