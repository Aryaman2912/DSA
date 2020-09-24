// This program contains a basic implementation of linked list data structure.

#include<bits/stdc++.h>
	
using namespace std;

struct Node{
	int data;
	Node* next;
};

int main(){

	// head is a pointer to the head node
	Node* head;
	head = NULL; // Empty list
	
	// Add a node to an empty list
	Node* temp = new Node();
	temp->data = 1;
	temp->next = NULL;
	head = temp;            // Head points to the first node

	// Add nodes to the end of a non empty list
	Node* temp1 = head;
	for(int i = 3; i <= 6; i++){
		temp = new Node();
		temp->data = i;
		temp->next = NULL;
		// Traversal of the list
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}

	// Print all elements of the list
	temp1 = head;
	cout <<"Elements of the list are: \n";
	while(temp1->next != NULL){
		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	// temp1 is currently the last node in the list
	cout << temp1->data << "\n";
}