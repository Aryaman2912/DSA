#include<bits/stdc++.h>
using namespace std;

// Variables declared globally
vector<int>edges[100];
vector<int>components[100];
vector<bool>visited(100);
vector<int>discovery_time(100);
vector<int>finish_time(100);
int cur_time = 0;

// Function to perform DFS
void dfs(int v,int component){
	// Mark the vertex as visited, store the component it belongs to
	// Also store its discovery time
	visited[v] = true;
	components[component].push_back(v);
	discovery_time[v] = cur_time;
	cur_time++;

	// Explore all the neighbors of the vertex
	for(std::vector<int>::iterator i = edges[v].begin(); i != edges[v].end(); ++i){
		if(!visited[*i]){
			dfs(*i,component);
		}
	}
	// Store the finishing time of the vertex and update the current time
	finish_time[v] = cur_time;
	cur_time++;
}

// Function to print the discovery and finish times of the laptop
void print_times(int n){
	cout << "The discovery time and finish time of the vertices are:\n";
	for(int i = 1; i <= n; i++){
		cout << i << " - " << discovery_time[i] << " " << finish_time[i] << "\n";
	}
}

// Function to print the components of the graph
void print_components(int component){
	if(component == 1)
		cout << "There is 1 component in the graph\n";
	else
		cout << "There are " << component << " components in the graph\n";
	for(int i = 1; i <= component; i++){
		cout << "The vertices in component " << i << " are: ";
		for(std::vector<int>::iterator j = components[i].begin(); j != components[i].end(); ++j){
			cout << *j << " ";
		}
		cout << endl;
	}
}

// Main function
int main(){
	// Input the graph
	int n,m,component = 0;
	cout << "Enter the number of vertices and edges in the graph: ";
	cin >> n >> m;
	cout << "Enter the edges of the graph: \n";
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	// Perform DFS on all vertices
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			component++;
			dfs(i,component);
		}
	}

	// Print times and components
	print_times(n);
	print_components(component);
}