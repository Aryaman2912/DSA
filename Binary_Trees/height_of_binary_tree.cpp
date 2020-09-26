// The below program contains the algorithm to find the height of a binary tree

#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
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

// Function to find the height of the binary tree
int Height(BstNode* root){
	// if 0 is returned when height of root is null, height of leaf will be 1
	if(root == NULL){
		return -1;
	}
	else{
		// return the maximum among the heights of left and right subtrees
		int left_ht = Height(root->left);
		int right_ht = Height(root->right);
		return max(left_ht,right_ht) + 1;
	}
}

int main(){
	BstNode* root = NULL;
	for(int i = 0; i < 20; i++){
		int num = 1 + rand()%20;
		cout << "Inserted " << num << " to the tree\n";
		root = Insert(root,num);
	}
	int tree_height = Height(root);
	cout << "The height of the binary tree is " << tree_height << "\n";
}