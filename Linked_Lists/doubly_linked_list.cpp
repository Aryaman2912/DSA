#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;

// Function to create a new node
struct Node* get_new_node(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

// Function to insert a node at the head of the list
void insert_at_head(int x){
	Node* new_node = get_new_node(x);
	if(head == NULL){
		head = new_node;
		return;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
}

// Function to insert a node at the tail
void insert_at_tail(int x){
	Node* new_node = get_new_node(x);
	new_node->prev = tail;
	tail->next = new_node;
	tail = new_node;
}

// Function to print the list in forward order
void print(){
	struct Node* temp = head;
	cout << "The list in forward order is\n";
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Function to print the list in reverse order
void print_reverse(){
	struct Node* temp = tail;
	cout << "The list in reverse order is\n";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}
int main(){
	head = NULL;
	tail = head;          // tail points to the last node
	insert_at_head(6);
	insert_at_head(5);
	insert_at_head(4);
	insert_at_head(3);
	insert_at_head(2);
	insert_at_head(1);
	insert_at_tail(7);
	insert_at_tail(8);
	print();
	print_reverse();
}