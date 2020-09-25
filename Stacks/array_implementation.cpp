#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000005

int Stack[MAX_SIZE];
int top = -1;

// Function to add an element to the top of the stack
void Push(int x){
	// Error handling
	if(top == MAX_SIZE-1){
		cout << "Congrats on the stack overflow\n";
		return;
	}
	Stack[++top] = x;
}

//Function to remove the top element of the stack
void Pop(){
	// Error handling
	if(top==-1){
		cout << "Stack is empty\n";
		return;
	}
	top--;
}

// Function to return the top element of the stack
int Top(){
	// Error handling
	if(top==-1){
		cout << "Stack is empty\n";
		return 0;
	}
	return Stack[top];
}

// Function to check if the stack is empty
bool isEmpty(){
	if(top==-1)
		return true;
	return false;
}

// It is not possible to access all the elements of a stack
// this is just to understand how the stack works
void Print(){
	cout << "The current stack is: \n";
	for(int i = 0; i <= top; i++){
		cout << Stack[i] << " ";
	}
	cout << endl;
}

// Main function
int main(){
	for(int i = 0; i <= 5;i++){
		Push(i);
		Print();
	}
	Pop();
	Print();
	cout << "The top element is " << Top() << "\n";
}