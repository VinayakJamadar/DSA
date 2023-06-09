// Problem: Prim's Algorithm - Minimum Spanning Tree
// Article Link: https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/


// To find sum of weights of edges of the Minimum Spanning Tree


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(E * log(E)) + O(E * log(E))~ O(E * log(E))
// Reason: O(E * log(E)) for The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take log(E) time. And O(E * log(E)) for inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a log(E) time complexity.


// Space Complexity: O(E) + O(V)
// Reason: O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.


// Intuition:
// The intuition of this algorithm is the greedy technique used for every node. If we carefully observe, for every node, we are greedily selecting its unvisited adjacent node with the minimum edge weight(as the priority queue here is a min-heap and the topmost element is the node with the minimum edge weight). Doing so for every node, we can get the mstWt of all the edge weights of the minimum spanning tree and the spanning tree itself(if we wish to) as well.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Function to find mstWt of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[]) {
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;

		int mstWt = 0;
		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});

		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			mstWt += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return mstWt;
	}
};


int main() {
	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}
	Solution obj;
	int mstWt = obj.spanningTree(V, adj);

	// Output: The sum of all the edge weights: 5
    cout << "The sum of all the edge weights: " << mstWt << endl;
	return 0;
}