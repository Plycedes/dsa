#include <iostream>

using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int x){
        data = x;
    }
};

void pushFront(Node** headref, Node** endref, int newData){
    Node* newNode = new Node(newData);   
    newNode->next=(*headref);
    (*headref)->prev=newNode;
    (*headref)=newNode;
    (*endref)->next=newNode;   
}

void pushBack(Node** headref, Node** endref, int newdata){
    Node* newNode = new Node(newdata);
    newNode->next=(*headref);
    (*endref)->next=newNode;
    newNode->prev=(*endref);
    (*headref)->prev=newNode;
    (*endref)=newNode;
}

void printFD(Node* head){
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

void printBD(Node** end){
    Node* temp = (*end);
    do{
        cout<<temp->data<<" ";
        temp=temp->prev;
    }while(temp!=(*end));
    cout<<endl;
}

int main(){
    Node* head = new Node(10);
    Node* middle = new Node(20);
    Node* end = new Node(30);

    head->prev=end;
    head->next=middle;
    middle->prev=head;
    middle->next=end;
    end->prev=middle;
    end->next=head;

    pushFront(&head, &end, 40);
    pushFront(&head, &end, 60);
    pushBack(&head, &end, 50);
    pushBack(&head, &end, 70);

    printFD(head);
    printBD(&end);
    return 0;
}