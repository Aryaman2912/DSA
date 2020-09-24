#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

// Function to insert a node at the beginning
void Insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Function to print the list
void Print(){
	Node* temp = head;
	cout << "The list is: \n";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void Reverse(Node* p){
	if(p->next == NULL){
		head = p;
		return;
	}
	Reverse(p->next);      // Recursive call
	p->next->next = p;
	p->next = NULL;
}

int main(){
	head = NULL;
	Insert(6);
	Insert(5);
	Insert(4);
	Insert(3);
	Insert(2);
	Insert(1);       // 1 2 3 4 5 6
	Print();
	Reverse(head);
	Print();
}