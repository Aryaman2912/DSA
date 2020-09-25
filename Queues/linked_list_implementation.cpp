#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Push(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if(front == NULL and rear == NULL){
		front = temp;
		rear = front;
		return;
	}
	rear->next = temp;
	rear = temp;	
}

void Pop(){
	Node* temp = front;
	if(front==NULL){
		cout << "The queue is empty\n";
		return;
	}
	if(front == rear){
		front = NULL;
		rear = NULL;
		return;
	}
	front = front->next;
	delete temp;	
	return;
}

void Front(){
	if(front == NULL){
		cout << "The queue is empty\n";
		return;
	}
	cout << "The front element of the queue is " << front->data << "\n";
}

void Print(){
	Node* temp = front;
	cout << "The current queue is\n";
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main(){
	Push(1);Print();
	Push(2);Print();
	Push(3);Print();
	Push(4);Print();
	Push(5);Print();
	Pop();Print();
	Front();
}