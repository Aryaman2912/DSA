// This program contains an algorithm to find the minimum and maximum element in BST

#include<bits/stdc++.h>

using namespace std;

struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new node
BstNode* get_new_node(int value){
	BstNode* node = new BstNode();
	node->data = value;
	node->left = node->right = NULL;
	return node;
}

// Function to insert a node in the BST
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

// Function to find the smallest element of the BST
int FindMin(BstNode* root){
	// keep traversing toward the left of the tree until the leftmost leaf is found
	// the leftmost leaf is the smallest element
	if(root->left == NULL){
		return root->data;
	}
	else{
		return FindMin(root->left);
	}
}

// Function to find the largest element of the BST
int FindMax(BstNode* root){
	// keep traversing toward the right of the tree until the rightmost leaf is found
	// the rightmost leaf is the largest element
	if(root->right == NULL){
		return root->data;
	}
	else{
		return FindMax(root->right);
	}
}
int main(){
	// initialize empty tree
	BstNode* root = NULL;
	int search;

	// insert 10 randomly chosen elements to the tree
	for(int i = 1; i < 20; i++){
		int value = 1 + rand()%15;
		cout << "Inserted " << value << " in the binary tree\n";
		root = Insert(root,value);
	}
	cout << "Done\n";
	cout << "Minimum element in the BST is " << FindMin(root) << "\n";
	cout << "Maximum element in the BST is " << FindMax(root) << "\n";
}
