#include <iostream>

using namespace std;

struct QNode {
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue() { front = rear = NULL; }

	void enQueue(int x)
	{		
		QNode* temp = new QNode(x);

		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
        cout<<"Enqueued: "<<x<<endl;
	}

	void deQueue()
	{
		if (front == NULL)
			return;

		QNode* temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

        cout<<"Dequeued: "<<temp->data<<endl;
		delete (temp);
	}
};

int main()
{
	Queue q;
	cout<<endl;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();	
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data<<endl;
	cout<<endl;
    return 0;
}