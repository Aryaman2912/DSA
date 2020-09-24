#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

Node* head;

// Function to insert a node at the beginning of the list
void Insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Function to reverse the list using stack
void Reverse(){
	Node* temp = head;
	stack<Node*> list;
	while(temp!=NULL){
		list.push(temp);
		temp = temp->next;
	}
	temp = list.top();
	head = temp;
	list.pop();
	while(!list.empty()){
		temp->next = list.top();
		list.pop();
		temp = temp->next;
	}
	temp->next = NULL;
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

// Function to print the reversed list
void Print_reverse(){
	Node* temp = head;
	cout << "The reversed list is: \n";
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main(){
	head = NULL;
	int n;
	cout << "How many elements are you entering?\n";
	cin >> n;
	cout << "Enter the elements: \n";
	while(n--){
		int x;
		cin >> x;
		Insert(x);
	}
	Reverse();
	Print();
	Reverse();
	Print_reverse();
}