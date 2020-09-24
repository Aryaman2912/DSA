#include<bits/stdc++.h>
using namespace std;

// Each element of the stack will be a node
struct Node{
	int data;
	Node* next;
};

Node* top = NULL;

// Pushing into the stack is equivalent to inserting a node at the head of the list
void Push(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

// Pop is equivalent to removing the first node
void Pop(){
	if(top==NULL){
		cout << "Stack is empty\n";
		return;
	}
	Node* temp = top;
	top = top->next;
	delete temp;
}

// Function to obtain the top element of the stack
int Top(){
	if(top==NULL){
		cout << "Stack is empty";
		return 0;
	}
	return top->data;
}

// Function to determine if the list is empty
bool isEmpty(){
	if(top==NULL)
		return true;
	return false;
}

// It is no possible to access all elements of a stack
// this is just to show how it works
void Print(){
	Node* temp = top;
	cout << "The current stack is\n";
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Main function
int main(){
	Push(1);Print();
	Push(2);Print();
	Push(3);Print();
	Push(4);Print();
	Push(5);Print();
	Pop();Print();
	cout << "The top element is " << Top() << "\n";

}