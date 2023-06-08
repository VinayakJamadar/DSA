// Problem: Topological Sort Algorithm using BFS (Kahn's Algorithm)

// Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0

// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)

// Time Complexity: O(V + E)
// Reason: Time complexity of bfs traversal in directed graph

// Space Complexity: O(2V)
// Reason: Space taken 'indegree' array and 'q' queue.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[]) {
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			
			// node is in your topo sort
			// so please remove it from the indegree
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
		return topo;
	}
};


int main() {
	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}