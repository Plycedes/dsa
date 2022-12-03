#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

void push(Node** headref, int newData){
    Node* newNode = new Node();
    newNode->data=newData;
    newNode->next= *headref;
    *headref=newNode;
}

void pushBack(Node** headref, int newData){
    Node* newNode = new Node();
    Node* last = *headref;
    newNode->data=newData;
    newNode->next=NULL;
    if(*headref==NULL){
        *headref = newNode;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
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
}

int printRand(Node* head, int index){
    int count=1;
    while(count!=index){
        head=head->next;
        count++;
    }
    return head->data;
}

void deleteNode(Node** headref, int key){
    Node* temp = *headref;
    Node* prev = NULL;

    if(temp != NULL && temp->data==key){
        *headref = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL and temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    delete temp;    
}

int main(){
    Node* head = new Node();
    Node* end = new Node();   
    
    head->data=10;
    end->data=20;

    head->next=end;

    push(&head, 30);
    pushBack(&end, 40);
    pushAt(head, 50, 4);
    pushBack(&end, 60);

    deleteNode(&head, 40);

    printList(head);       
    
    return 0;
}