// Problem: Detect cycle in a directed graph using DFS

// Approach 2: Using only 'vis' array (i.e Using one array)

// Notes:
// 1. if vis = 0 && pathVis = 0 
// 		then vis = 0 (i.e if node is not yet visited then mark vis = 0)
// 2. if vis = 1 && pathVis = 1 
// 		then vis = 1 (i.e if node is visited and also pathVis then mark vis = 1)
// 3. if vis = 1 && pathVis = 0
//   	then vis = 2 (i.e if node is visited and not pathVis then mark vis = 2)

// V = Number of Nodes
// E = Number of Edges

// Time Complexity: O(V + E)
// Reason: Time complexity of dfs traversal in directed graph

// Space Complexity: O(V)
// Reason: Space taken 'vis' array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, int vis[], vector<int> adj[]) {
		vis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the adjacent node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, vis, adj) == true)
					return true;
			}
			// if the adjacent node has been previously visited
			// but it has to be visited on the same path
			else if (vis[it] == 1) {
				return true;
			}
		}

		vis[node] = 2;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, vis, adj) == true) return true;
			}
		}
		return false;
	}
};


int main() {
	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

    if (ans) cout << "Graph contains Cycle." << endl;
    else cout << "Graph does not contains Cycle." << endl;

	return 0;
}