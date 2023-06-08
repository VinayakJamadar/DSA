// Problem: Detect a Cycle in Directed Graph by Topological Sort using BFS (Kahn's Algorithm)

// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)
// 3. Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0

// Time Complexity: O(V + E)
// Reason: Time complexity of topological sort using bfs traversal (i.e. Kahn's Algorithm) in directed graph

// Space Complexity: O(2V)
// Reason: Space taken 'indegree' array and 'q' queue.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Function to detect cycle in a directed graph
	bool isCyclic(int V, vector<int> adj[]) {
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
		
		int cnt = 0;
		// Uncomment below line if you want to use with 'topo' vector
		// vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			cnt++;
			// Uncomment below line if you want to use with 'topo' vector
			// topo.push_back(node);
            
			// node is in your topo sort
			// so please remove it from the indegree
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

        if(cnt == V) return false;
        else return true;
		// Uncomment below line if you want to use with 'topo' vector
		// if(topo.size() == V) return false;
		// else return true;
	}
};


int main() {
	//V = 5;
	vector<int> adj[6] = {{1}, {2}, {3, 4}, {1}, {}};
	int V = 5;
	Solution obj;

	bool ans = obj.isCyclic(V, adj);

    if (ans) cout << "Graph contains Cycle." << endl;
    else cout << "Graph does not contains Cycle." << endl;

	return 0;
}