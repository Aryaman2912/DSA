// This program contains a few algorithms to check if a binary tree is a BST

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

// Function to create a new node
Node* GetNewNode(int value){
	Node* node = new Node();
	node->data = value;
	node->left = node->right = NULL;
	return node;
}

// Function to insert a new node into the BST
Node* Insert(Node* root, int value){	
	// if tree is empty, assign node to root
	if(root == NULL){
		// create new node with data field as value and left, right pointers as null
		Node* node = GetNewNode(value);
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

// Function to create a binary tree that is not a BST. Nodes are always added to the left
Node* InsertLeft(Node* root,int val){
	Node* new_node = GetNewNode(val);
	if(root == NULL){
		root = new_node;
		return root;
	}
	Node* temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	temp->left = new_node;
	return root;
}

// Function to check if all elements in a subtree are greater than a particular value
bool IsGreaterThan(Node* root,int value){
	if(root == NULL){
		return true;
	}
	// check recursively
	if(root->data > value and IsGreaterThan(root->left,value) and IsGreaterThan(root->right,value)){
		return true;
	}
	else{
		return false;
	}
}

// Function to check if all elements in a subtree are lesser than a particular value
bool IsLesserThan(Node* root,int value){
	if(root == NULL){
		return true;
	}
	// check recursively
	if(root->data <= value and IsLesserThan(root->right,value) and IsLesserThan(root->left,value)){
		return true;
	}
	else{
		return false;
	}
}

// First algorithm to check if a tree is a BST. Naive algorithm
bool IsBST1(Node* root){
	if(root == NULL){
		return true;
	}
	if(IsGreaterThan(root->right,root->data) and IsLesserThan(root->left,root->data) and IsBST1(root->left) and IsBST1(root->right)){
		return true;
	}
	else{
		return false;
	}
}

// Second algorithm to check if a tree is a BST. More efficient algorithm
// This algorithm assigns bounds to each node
bool IsBST2(Node* root,long int min_value,long int max_value){
	if(root == NULL){
		return true;
	}
	if(root->data > min_value and root->data <= max_value and IsBST2(root->left,min_value,root->data) and IsBST2(root->right,root->data,max_value)){
		return true;
	}
	else{
		return false;
	}
}

// Function for Inorder traversal order of a tree
void Inorder(Node* root){
	if(root == NULL){
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

int main(){
	Node* root1 = NULL;
	Node* root2 = NULL;
	for(int i = 0;i < 10;i++){
		int val = 1 + rand()%10;
		root1 = Insert(root1,val);
		root2 = InsertLeft(root2,val);
	}
	bool ok1 = false,ok2 = false;
	ok1 = IsBST1(root1) and IsBST2(root1,-100000,100000);
	ok2 = IsBST1(root2) or IsBST2(root2,-100000,100000);
	cout << "Inorder traversal of the first tree results in\n";
	Inorder(root1);
	if(ok1){
		cout << "\nThe first tree is a binary tree\n";
	}
	else{
		cout << "\nThe first tree is not a binary tree\n";
	}
	cout << "Inorder traversal of the second tree results in\n";
	Inorder(root2);
	if(ok2){
		cout << "\nThe second tree is a binary tree\n";
	}
	else{
		cout << "\nThe second tree is not a binary tree\n";
	}
}
