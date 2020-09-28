// This program contains code to find the inorder successor of an element in a BST

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

// Function to search for a value in the BST
BstNode* Search(BstNode* root,int value){
	// if root is null, the element is not present in the tree
	if(root == NULL){
		return root;
	}
	// if the value at root is equal to the desired value,return its level
	if(root->data == value){
		return root;
	}
	// if the value at the root is greater than the desired value, search to the left of the node
	else if(value < root->data){
		return Search(root->left,value);
	}
	// if the value at the root is lesser than the desired value, search to the right of the node
	else{
		return Search(root->right,value);
	}
}

// Function for inorder traversal of the tree
void Inorder(BstNode* root){
	if(root == NULL){
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

// Function to find the successor of a node
BstNode* GetSuccessor(BstNode* root, int value){
	BstNode* current = Search(root, value);
	// case 1 - right subtree is not null
	if(current->right != NULL){
		BstNode* temp = current->right;
		while(temp->left != NULL){
			temp = temp->left;
		}
		return temp;
	}
	// case 2 - right subtree is null
	else{
		BstNode* successor = NULL;
		BstNode* ancestor = root;
		while(ancestor->data != current->data){
			if(ancestor->data < current->data){
				ancestor = ancestor->right;
			}
			else if(ancestor->data >= current->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
		}
		return successor;
	}
}
int main(){
	BstNode* root = NULL;
	// create perfect binary tree
	root = Insert(root,20);root = Insert(root,10);root = Insert(root,40);root = Insert(root,5);root = Insert(root,15);
	root = Insert(root,30);root = Insert(root,50);root = Insert(root,1);root = Insert(root,7);root = Insert(root,14);
	root = Insert(root,22);root = Insert(root,31);root = Insert(root,45);root = Insert(root,55);
	cout << "Inorder traversal of the tree:\n";
	Inorder(root);
	BstNode* node = GetSuccessor(root,15);
	cout << "\nThe inorder successor of 15 is " << node->data <<"\n";
	node = GetSuccessor(root,20);
	cout << "The inorder successor of 20 is " << node->data <<"\n";
	node = GetSuccessor(root,55);
	if(node == NULL){
		cout << "55 has no inorder successor in the BST\n";
	}
	else{
		cout << "The inorder successor of 55 is " << node->data <<"\n";
	}

}