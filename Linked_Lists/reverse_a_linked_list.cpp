// This program contains the implementation of reversing a linked list without recursion
#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

// Function to reverse the linked list
void Reverse(){
	Node *prev,*current,*next;
	current = head;
	prev = NULL;
	// while iterating through the list,keep reversing the links simultaneously as we move from node to node
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// Function to insert a node at the beginning of the list
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

// Main function
int main(){
	head = NULL;
	for(int i = 1; i <= 6; i++){
		Insert(i);
	}
	Print();
	Reverse();
	Print();
}