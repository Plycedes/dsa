#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void pushFront(Node** headref, Node** endref, int newData){
    Node* newNode = new Node();
    newNode->data=newData;
    if((*headref)==NULL){
        (*headref) = newNode;
    }
    newNode->next= (*headref);    
    (*headref) = newNode;
    (*endref)->next = newNode;
    cout<<"Pushed at front: "<<newData<<endl;
}

void pushBack(Node** headref, Node** endref, int newData){
    Node* newNode = new Node();
    newNode->data=newData;
    if((*headref)==NULL){
        (*headref) = newNode;
    }
    newNode->next= (*headref);  
    (*endref)->next = newNode; 
    (*endref) = newNode;
    cout<<"Pushed at back: "<<newData<<endl;
}

void pushAt(Node* head, int newData, int index ){
    int count=1;
    index-=1;
    while(count!=(index)){
        head=head->next;
        count++;
    }
    Node* newNode = new Node();
    newNode->data=newData;
    newNode->next=head->next;
    head->next=newNode;
    cout<<"Pushed at "<<index<<": "<<newData<<endl;
}

void popFront(Node** headref, Node** endref){
    Node* temp = new Node();
    temp = (*headref);
    (*headref) = (*headref)->next;
    (*endref)->next = (*headref);
    cout<<"Popped from front: "<<temp->data<<endl;
    delete(temp);
}

void popBack(Node** headref, Node** endref){
    Node* temp = new Node();
    Node* prev = new Node();
    prev = NULL;
    temp = (*headref)->next;
    while(temp!=(*endref)){
        prev = temp;
        temp = temp->next;
    }    
    (*endref) = prev;
    prev->next = (*headref);
    cout<<"Popped from back: "<<temp->data<<endl;
    delete(temp);
}

void popAt(Node** head, int index){   
    Node* temp = (*head);
    Node* prev = NULL;
    int count = 1;
    while(count != index){
        prev = temp;
        temp=temp->next;
        count++;
    }
    prev->next=temp->next;
    cout<<"Popped "<<temp->data<<" from "<<index<<endl;
    delete(temp);    
}

void printList(Node* head){
    Node* temp = head;     
    do{
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=head);  
}

int main(){
    Node* head = new Node();
    Node* end = new Node();

    head->next = end;
    end->next = head;

    head->data = 10;
    end->data = 20;

    pushFront(&head, &end, 30);
    pushBack(&head, &end, 40);
    pushAt(head, 50, 3);

    popFront(&head, &end);
    pushFront(&head, &end, 60);
    popBack(&head, &end);

    pushBack(&head, &end, 70);

    popAt(&head, 3);

    printList(head);

    return 0;
}