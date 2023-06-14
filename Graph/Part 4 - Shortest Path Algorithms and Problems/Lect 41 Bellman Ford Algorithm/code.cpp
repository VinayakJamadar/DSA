// Problem: Bellman Ford Algorithm
// Article Link: https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(V * E)
// Reason: O(V * E) for using two nested 'for' loops with V iterations for Outer and E for Inner 'for' loop


// Space Complexity: O(V)
// Reason: for O(V) 'distTo' array


// Approach: 'V' Relaxation of all Edges


// Note:
// 1. While learning Dijkstra’s algorithm, we came across the following two situations, where Dijkstra’s algorithm failed:
// 		i. If the graph contains negative edges.
//		ii. If the graph has a negative cycle (In this case Dijkstra’s algorithm fails to minimize the distance, keeps on running, and goes into an infinite loop. As a result it gives TLE error).
// 2. Bellman-Ford’s algorithm successfully solves these problems. It works fine with negative edges as well as it is able to detect if the graph contains a negative cycle.
// 3. But this algorithm is only applicable for directed graphs.
// 4. In order to apply this algorithm to an undirected graph, we just need to convert the undirected edges into directed edges.
// 5. Edges can be in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;

        // V-1 relaxation of all Edges to get shortest path of all the nodes from source 'S' node
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}

		// Vth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}

		return dist;
	}
};


int main() {
	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);

    // Output: 0 5 3 3 1 2
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}