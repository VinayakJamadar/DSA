// Problem: Floyd Warshall Algorithm
// Article Link: https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(V^3)
// Reason: As we have three nested loops each running for V times.


// Space Complexity: O(V^2)
// Reason: Due to storing the adjacency matrix of the given graph.


// Note:
// 1. Dijkstra’s Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms where we are given a single source node and are asked to find out the shortest path to every other node from that given source.
// 2. But in the Floyd Warshall algorithm, we need to figure out the shortest distance from each node to every other node.
// 3. Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well.


// Intuition:
// The intuition is to check all possible paths between every possible pair of nodes and to choose the shortest one. Checking all possible paths means going via each and every possible node.


// Approach: 
// The algorithm is not much intuitive as the other ones’. It is more of a brute force, where all combinations of paths have been tried to get the shortest paths. Nothing to panic much with the intuition, it is a simple brute force approach on all paths. Focus on the three ‘for’ loops.
// Formula:
// matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])
// where i = source node, j = destination node and k = the node via which we are reaching from i to j.


// The follow-up questions for interviews:

// Question1: How to detect a negative cycle using the Floyd Warshall algorithm?
// Answer1:
// i. Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative. The following illustration is an example of a negative cycle:
// ii. We have previously said that the cost of reaching a node from itself must be 0. But in the above graph, if we try to reach node 0 from itself we can follow the path: 0->1->2->0. In this case, the cost to reach node 0 from itself becomes -3 which is less than 0. This is only possible if the graph contains a negative cycle.
// iii. So, if we find that the cost of reaching any node from itself is less than 0, we can conclude that the graph has a negative cycle.

// Question2: What will happen if we will apply Dijkstra’s algorithm for this purpose?
// Answer2:
// i. If the graph has a negative cycle: We cannot apply Dijkstra’s algorithm to the graph which contains a negative cycle. It will give TLE error in that case.
// ii. If the graph does not contain a negative cycle: In this case, we will apply Dijkstra’s algorithm for every possible node to make it work like a multi-source shortest path algorithm like Floyd Warshall. The time complexity of Floyd Warshall is O(V^3) whereas if we apply Dijkstra’s algorithm for the same purpose the time complexity reduces to O(V*(E*logV)). 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int V = matrix.size();

		// In question, If path is not possible from i to j then matrix[i][j] == -1
		// But in algorithm we need infinite (i.e 1e9) if path is not possible from i to j
		// So we replace -1 with infinite (i.e 1e9)
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				// Also set weight of self edge as '0' (zero)
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		// Code to detect a negative cycle in Floyd Warshall Algorithm
		// for (int i = 0; i < V; i++) {
		// 	if(matrix[i][i] < 0) {
		// 		cout << "Negative Cycle" << endl;
		// 	}
		// }


		// In question, If path is not possible from i to j then matrix[i][j] == -1
		// But using algorithm we need infinite (i.e 1e9) if path is not possible from i to j
		// So we replace back infinite (i.e 1e9) to -1
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};


int main() {
	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	// Output:
	// 0 2 5 -1
	// 1 0 3 -1
	// -1 -1 0 -1
	// 3 5 4 0

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}