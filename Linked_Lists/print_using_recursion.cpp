// This program contains code to print all elements of a linked list using recursion

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

// To print in forward order, we print the data field and then make the recursive call
void Print(Node* temp){
	if(temp == NULL){
		cout << endl;
		return;
	}
	cout << temp->data << " ";
	Print_reverse(temp->next);
}

// To print in reverse order, we first make a recursive call and then print the data field
void Print_reverse(Node* temp){
	if(temp == NULL){
		cout << endl;
		return;
	}
	Print_reverse(temp->next);
	cout << temp->data << " ";
}

int main(){
	head = NULL;
	for(int i = 6; i >= 1; i--){
		Insert(i);
	}
	cout << "The list in forward order is\n";    // 1 2 3 4 5 6
	Print(head);
	cout << "The list in reverse order is\n";    // 6 5 4 3 2 1
	Print_reverse(head);
}