// This program contains an implementation of Breadth First Search

#include<bits/stdc++.h>
using namespace std;

// node stores attributes of each node of the graph
// colour indicates if a node has been visited
// distance represents length of path from root to node
// predecessor is the ancestor of a node
struct node{
	string colour;
	int distance;
	int predecessor;
};

// Function to perform BFS
void BFS(vector<int>edges[],int root){
	vector<node>attributes(8);
	// Assign initial attributes to all nodes
	attributes[root].colour = "black";
	attributes[root].distance = 0;
	attributes[root].predecessor = -1;
	for(int i = 1; i < 8; i++){
		attributes[i].colour = "white";
		attributes[i].distance = 10000000;
		attributes[i].predecessor = -1;
	}
	// Queue to keep track of unvisited nodes
	queue<int>Q;
	Q.push(root);
	while(!Q.empty()){
		int i = Q.front();
		cout << i << " ";
		// assign colour black to a node that is visited to prevent repitition
		for(auto it:edges[i]){
			if(attributes[it].colour == "white"){
				attributes[it].colour = "black";
				attributes[it].distance = attributes[i].distance + 1;
				attributes[it].predecessor = i;
				Q.push(it);
			}
		}
		Q.pop();
		attributes[i].colour = "black";
	} 
}
int main(){
	int n = 8;
	vector<int>edges[8];
	// Adjacency list representation of the graph
	edges[0].push_back(1);edges[0].push_back(2);edges[0].push_back(3);
	edges[1].push_back(0);edges[1].push_back(4);
	edges[2].push_back(0);edges[2].push_back(5);edges[2].push_back(6);
	edges[3].push_back(0);edges[3].push_back(7);
	edges[4].push_back(1);
	edges[5].push_back(2);
	edges[6].push_back(2);
	edges[7].push_back(3);
	cout << "Order of traversal of BFS is\n";
	BFS(edges,0);          // Arguements are adjacency list and root node
	cout << endl;
}