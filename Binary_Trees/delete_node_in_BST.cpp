// This program contains code to delete a node in a BST

#include<bits/stdc++.h>
using namespace std;

struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

// Function to create a new node
BstNode* GetNewNode(int value){
	BstNode* node = new BstNode();
	node->data = value;
	node->left = node->right = NULL;
	return node;
}

// Function to insert a new node into the BST
BstNode* Insert(BstNode* root, int value){	
	// if tree is empty, assign node to root
	if(root == NULL){
		// create new node with data field as value and left, right pointers as null
		BstNode* node = GetNewNode(value);
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

// Function to find the node with smallest value in a subtree
BstNode* FindMin(BstNode* root){
	// keep traversing toward the left of the tree until the leftmost leaf is found
	// the leftmost leaf is the smallest element
	if(root->left == NULL){
		return root;
	}
	else{
		return FindMin(root->left);
	}
}

// Function for inorder traversal of the BST
void Inorder(BstNode* root){
	if(root == NULL){
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

// Function to delete a node in the BST
BstNode* Delete(BstNode* root,int value){
	if(root == NULL){
		return root;
	}
	// Traverse the right subtree if the needed value is lesser than the root value
	else if(value < root->data){
		root->left = Delete(root->left,value);
	}
	// Traverse the left subtree if the needed value is greater than the root value
	else if(value > root->data){
		root->right = Delete(root->right,value);
	}
	// 3 cases once the required node is found
	else if(value == root->data){
		// case 1 - no left and right subtrees 
		if(root->left == NULL and root->right == NULL){
			delete root;
			root = NULL;
		}
		// case 2 - either left subtree is null or right subtree is null
		else if(root->left == NULL){
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3 - both let and right subtrees are present
		else{
			BstNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,root->data);

		}
	}
	return root;

}
int main(){
	BstNode* root = NULL;
	// create perfect binary tree
	root = Insert(root,20);root = Insert(root,10);root = Insert(root,40);root = Insert(root,5);root = Insert(root,15);
	root = Insert(root,30);root = Insert(root,50);root = Insert(root,1);root = Insert(root,7);root = Insert(root,14);
	root = Insert(root,17);root = Insert(root,22);root = Insert(root,31);root = Insert(root,45);root = Insert(root,55);
	cout << "Inorder traversal of the tree:\n";
	Inorder(root);
	root = Delete(root,1);
	cout << "\nInorder traversal of the new tree:\n";
	Inorder(root);
	root = Delete(root,40);
	cout << "\nInorder traversal of the new tree:\n";
	Inorder(root);
	
}
