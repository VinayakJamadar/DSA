// Problem: Find Eventual Safe States using DFS

// Approach 1: Using'vis' and 'pathVis' arrays (i.e Using two arrays)

// V = Number of Nodes
// E = Number of Edges

// Time Complexity: O(V + E)
// Reason: Time complexity of dfs traversal in directed graph

// Space Complexity: O(2V)
// Reason: Space taken 'vis' and 'pathVis' array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the adjacent node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, vis, pathVis, adj) == true)
					return true;
			}
			// if the adjacent node has been previously visited
			// but it has to be visited on the same path
			else if (vis[it] && pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, vis, pathVis, adj);
			}
		}
		
		// All the nodes with pathVis == 0 are Safe Nodes
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if(pathVis[i] == 0) safeNodes.push_back(i);
		}
		return safeNodes;
	}
};

int main() {
	//V = 12;
	vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, 
        {8},{9}};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}