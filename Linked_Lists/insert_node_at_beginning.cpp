// This program contains code to insert a node at the beginning of a linked list

#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

// Function to insert a node at the beginning of the linked list
void Insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Function to print the linked list in forward order
void Print(){
	Node* temp = head;
	cout << "The current list is: \n";
	// Traverse till the end of the list
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

// Main function
int main(){
	Node* head;
	head = NULL;
	int n;
	cout << "How many numbers do you want to enter? \n";
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cout << "Enter a number: \n";
		cin >> x;
		Insert(x);
		Print();
	}

}