#include<bits/stdc++.h>
using namespace std;

// the 'sorted' vector contains the reverse of the topological ordering after dfs is completed
vector<int>edges[100];
vector<int>sorted;
vector<bool>visited(100);

// Function to perform dfs recursively
void dfs(int v){
	// Mark the vertex as visited
	visited[v] = true;

	// Explore all the neighbors of the vertex
	for(std::vector<int>::iterator i = edges[v].begin(); i != edges[v].end(); ++i){
		if(!visited[*i]){
			dfs(*i);
		}
	}
	// Push the vertex into the sorted array after all its neighbors are visited
	sorted.push_back(v);
}

// Main function
int main(){
	// Input the graph
	int n,m;
	cout << "Enter the number of vertices and edges in the graph: ";
	cin >> n >> m;
	cout << "Enter the edges of the graph: \n";
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		// Edge goes from x to y
		edges[x].push_back(y);
	}
	// Perform dfs on unvisited vertices
	for (int i = 1; i <= n; ++i){
		if(!visited[i]){
			dfs(i);
		}
	}

	// Print sorted array in reverse order to obtain the topological ordering
	cout << "The topological ordering of the given graph is:\n";
	for(int i = n-1; i >= 0; i--){
		cout << sorted[i] << " ";
	}
	cout << endl;
}