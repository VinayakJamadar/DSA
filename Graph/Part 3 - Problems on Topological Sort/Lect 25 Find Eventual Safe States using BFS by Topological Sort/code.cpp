// Problem: Find Eventual Safe States using BFS by Topological Sort

// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)
// 3. Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0

// Time Complexity: O(V + E)
// Reason: Time complexity of topological sort using bfs traversal (i.e. Kahn's Algorithm) in directed graph

// Space Complexity: O(2V)
// Reason: Space taken 'indegree' vector and 'q' queue.


// Approach:
// 1. The node with outdegree 0 is considered to be a terminal node.
// 2. But the topological sort algorithm deals with the indegrees of the nodes.
// 3. So, to use the topological sort algorithm, we will reverse every edge of the graph. 
// 4. Now, the nodes with indegree 0 become the terminal nodes. 
// 5. After this step, we will just follow the topological sort algorithm using bfs traversal (i.e Kahn's Algorithm) as it is.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};

		// Reverse the edges
		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}

		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};

int main() {
	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}