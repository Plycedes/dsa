#include<iostream>
using namespace std;

class Student{
    public :
    string name,course;
    int roll,marks;
    Student* next;
};

void push_at(Student* head,string newName, string newCourse, int newRoll, int newMarks, int index)
{
  int count=1;
  while(count!=index-1)
  {
    head=head->next;
    count++;
  }
  Student* newNode = new Student();
    newNode->name = newName;
    newNode->course = newCourse;
    newNode->roll = newRoll;
    newNode->marks = newMarks;
  newNode->next=head->next;
  head->next=newNode;
  cout<<"Data of "<<newNode->name<<" has inserted."<<endl;
}

void del_Node(Student** head,int key)
{
    Student* temp = (*head);
    Student* prev =NULL;

    if(temp != NULL && temp->roll==key)
    {
        cout<<"Data of "<<temp->name<<" has deleted.";
        temp=temp->next;
        delete temp;
        return;
    }
    
    if(temp==NULL)
    {
        return;
    }

    while(temp!=NULL && temp->roll!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    cout<<"Data of "<<temp->name<<" has deleted."<<endl;
    prev->next=temp->next;
    delete temp;
}

void reversList(Student** head)
{
    Student* current = (*head);
    Student* nextN = NULL;
    Student* prev = NULL;

    while(current!=NULL)
    {
        nextN=current->next;
        current->next=prev;
        prev=current;
        current=nextN;
    }

    (*head)=prev;
    cout<<"List has been reversed."<<endl;
    
}

void printList(Student*head)
{
    while(head!=NULL)
    {
        cout<<head->name<<"\t\t\t";
        cout<<head->course<<"\t\t\t";
        cout<<head->roll<<"\t\t\t";
        cout<<head->marks<<"\t\t\t";
        //cout<<endl;
        head=head->next;
    }
}

void printRand(Student*head,int index)
{
    int count=1;
    while(count!=index)
    {
        head=head->next;
        count++;
    }
        cout<<head->name<<"\t\t\t";
        cout<<head->course<<"\t\t\t";
        cout<<head->roll<<"\t\t\t";
        cout<<head->marks<<"\t\t\t";
}


int main()
{
    Student*head= new Student();
    Student*end= new Student();

    cout<<endl<<endl;

    head->name="Arihant";
    head->course="B.tech.";
    head->roll=1;
    head->marks=91;
    cout<<"Data of "<<head->name<<" has added"<<endl;
    
    end->name="Aditya";
    end->course="B.tech";
    end->roll=8;
    end->marks=96;
    cout<<"Data of "<<end->name<<" has added"<<endl;

    head->next=end;

    push_at(head,"Abhay","B,tech",2,92,2);
    push_at(head,"Adeeba","B,tech",3,93,3);
    push_at(head,"Jagriti","B,tech",4,94,4);
    push_at(head,"Archi","B,tech",5,95,5);
    push_at(head,"Armaan","B,tech",6,96,6);
    push_at(head,"Gorish","B,tech",7,97,7);

    cout<<endl<<endl;
    
    del_Node(&head,5);
    del_Node(&head,8);

    cout<<endl<<endl;

    reversList(&head);

    cout<<"Final list :-";
    cout<<"\n\nName\t\t\tCourse\t\t\tRoll Number\t\tMarks"<<endl<<endl;
    printList(head);
    cout<<endl<<endl;

    return 0;
}