// Djikstra's algorithm for undirected graphs
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>edges[100];
vector<int>dist(100);

// Function to implement djikstra's algorithm
void djikstra(){
	// initialize all distances to infinity
	for(int i = 0; i < 100; i++)dist[i] = INT_MAX;
	dist[1] = 0;		// distance to first node is 0
	// priority queue stores pairs of {distance to a node,node}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,1});
	while(!q.empty()){
		pair<int,int>p = q.top();
		q.pop();
		int u = p.second,d = p.first;
		if(d > dist[u])continue;
		for(pair<int,int> pr: edges[u]){
			if(d+pr.second < dist[pr.first]){
				dist[pr.first] = d+pr.second;
				q.push({dist[pr.first],pr.first});
			}
		}
	}
}
int main(){
	int n,m;
	// Input
	cout << "Enter the number of vertices: ";
	cin >> n;
	cout << "Enter the number of edges: ";
	cin >> m;
	cout << "Enter the edges and their weights: \n";
	for(int i = 0; i < m; i++){
		int x,y,z;
		cin >> x >> y >> z;
		edges[x].push_back({y,z});
		edges[y].push_back({x,z});
	}
	// Function call
	djikstra();
	cout << "Shortest distances to all nodes from the first node is\n";
	for(int i = 2; i <= n; i++){
		cout << dist[i] << " ";
	}
	cout << endl;
}