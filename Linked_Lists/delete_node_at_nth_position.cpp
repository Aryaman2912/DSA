#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

// Function to delete a node a particular position
void Delete(int pos){
	Node* temp1 = head;        // Pointer to node
	// If n==1 then just change the value of the head node
	if(pos==1){
		head = temp1->next;
		delete temp1;          // Free the space of the temp1 variable
		return;
	}
	int i=0;
	// Traverse the linked list to the (pos-1)th node
	while(i != pos-2){
		temp1 = temp1->next;
		i++;
	}
	Node* temp2 = temp1->next;         //temp2 points to the (pos)th node 
	temp1->next = temp2->next;         // Now temp1 points to the (pos+1)th node
	
	  // Free the space of the temp2 variable	
	delete temp2;                    
}

// Function to insert a node at the beginning
void Insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Function to print the linked list
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
	head = NULL;     // List is empty
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Insert(6);
	Insert(7);
	Print();
	int pos,len = 7;
	while(1){	
		if(len==0){
			cout << "List is empty\n";
			break;
		}
		cout << "Which position do you want to delete?(0 to stop) \n";
		cin >> pos;
		if(pos<0||pos>len){
			cout << "Invalid position\n";
		}
		else if(pos==0){
			break;
		}
		else{
			Delete(pos);
			Print();
			len--;
		}
	}
}