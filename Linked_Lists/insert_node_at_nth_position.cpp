#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

//Function to insert a node at a particular position
void Insert(int pos,int x){
	// Declare a new node
	Node* temp = new Node();
	temp->data = x;
	int i = 0;
	Node* temp2 = head;
	// Traverse the list to find the (pos-1)th node
	while(i != pos-2 && temp2!=NULL){
		temp2 = temp2->next;
		i++;
	}
	// Create a link between the (pos)th node and the new node
	temp->next = temp2->next;
	// Create a link between the new node and the (pos-1)th node
	temp2->next = temp;
}

// Function to insert a node at the beginning
void Insert_at_beginning(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Function to print the list
void Print(){
	Node* temp = head;
	cout << "The current list is: \n";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main(){
	head = NULL;
	// Create a linked list with some sample elements
	Insert_at_beginning(1);
	Insert_at_beginning(2);
	Insert_at_beginning(3);
	Insert_at_beginning(4);
	Insert_at_beginning(5);
	Print();
	int pos,len=5;
	// User can input any number of elements
	while(1){
		cout << "Where do you want to enter the new number? (Press 0 to stop)\n";
		cin >> pos;
		if(pos==0){
			cout << "Thank you\n";
			break;
		}
		else if(pos>len){
			cout << "Invalid postition\n";
		}
		else{
			int x;
			cout << "Enter the value: \n";
			cin >> x;
			// For inserting at the beginning of the list, a different function is called
			if(pos==1)
				Insert_at_beginning(x);
			else
				Insert(pos,x);
			Print();
			len++;
		}
	}
}