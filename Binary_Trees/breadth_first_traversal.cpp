// The below program demonstrates breadth first traversal of a binary tree

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

// Function to perform breadth first traversal of binary tree
void BreadthFirstTraversal(BstNode* root){
	// handle empty tree case
	if(root == NULL){
		return;
	}
	// we use a queue to store the addresses of nodes that we have to visit
	queue<BstNode*> Q;
	Q.push(root);
	// when the queue is empty, we are done
	while(!Q.empty()){
		BstNode* current = Q.front();
		cout << current->data <<" ";
		if(current->left != NULL)
			Q.push(current->left);
		if(current->right != NULL)
			Q.push(current->right);
		Q.pop();
	}
	cout << endl;
}

int main(){
	BstNode* root = NULL;
	// create perfect binary tree
	root = Insert(root,20);root = Insert(root,10);root = Insert(root,40);root = Insert(root,5);root = Insert(root,15);
	root = Insert(root,30);root = Insert(root,50);root = Insert(root,1);root = Insert(root,7);root = Insert(root,14);
	root = Insert(root,17);root = Insert(root,22);root = Insert(root,31);root = Insert(root,45);root = Insert(root,55);
	cout << "Breadth first traversal happens in the following order:\n";
	BreadthFirstTraversal(root);
}