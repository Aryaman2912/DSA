// This program contains an implementation of binary search tree 
// and some of its basic functions

#include<bits/stdc++.h>

using namespace std;

// Node declaration
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

// This variable keeps a check of the depth of the value being searched for in Search function
int level = 0;

// Function to create a new node
BstNode* get_new_node(int value){
	BstNode* node = new BstNode();
	node->data = value;
	node->left = node->right = NULL;
	return node;
}

// Function to insert a new node into the BST
// root is not necessarily the root of the tree
// it is the node at which we currently are trying to insert the value
BstNode* Insert(BstNode* root, int value){	
	// if tree is empty, assign node to root
	if(root == NULL){
		// create new node with data field as value and left, right pointers as null
		BstNode* node = get_new_node(value);
		root = node;
	}
	// if value of new node is less than or equal to the data at current root, insert to the left
	else if(value <= root->data){
		root->left = Insert(root->left,value);
	}
	// if value of new node is greater than the data at current root, insert to the right
	else{
		root->right = Insert(root->right,value);
	}
	return root;
}
// Function to search for a value in the BST
int Search(BstNode* root,int value){
	// if root is null, the element is not present in the tree
	if(root == NULL){
		return -1;
	}
	// if the value at root is equal to the desired value,return its level
	if(root->data == value){
		return level;
	}
	// if the value at the root is greater than the desired value, search to the left of the node
	else if(value < root->data){
		level++;
		return Search(root->left,value);
	}
	// if the value at the root is lesser than the desired value, search to the right of the node
	else{
		level++;
		return Search(root->right,value);
	}
}

// Main function
int main(){
	// initialize empty tree
	BstNode* root = NULL;
	int search;

	// insert 10 randomly chosen elements to the tree
	for(int i = 1; i < 10; i++){
		int value = 1 + rand()%10;
		cout << "Inserted " << value << " in the binary tree\n";
		root = Insert(root,value);
	}
	cout << "Done\n";

	// search for a desired set of values
	cout << "How many elements do you want to search for?\n";
	cin >> search;

	for(int i = 0; i < search; i++){
		int element;
		cout << "Enter the element you want to search for\n";
		cin >> element;
		level = 0;
		// flag is the depth of the element in the BST or -1 if the element is not present
		int flag = Search(root,element);
		if(flag == -1){
			cout << element << " is not present in the binary search tree\n";
		}
		else{
			cout << element << " is present at level " << flag << "\n";
		}
	}
}