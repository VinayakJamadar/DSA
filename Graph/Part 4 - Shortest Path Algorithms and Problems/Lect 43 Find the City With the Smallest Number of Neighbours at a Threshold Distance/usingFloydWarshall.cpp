// Problem: Find the City With the Smallest Number of Neighbours at a Threshold Distance
// Article Link: https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/


// V = n = Number of Nodes
// E = m = Number of Edges


// Using Floyd Warshall Algorithm.


// Time Complexity: O(V^3) or O(n^3)
// Reason: As we have three nested loops each running for V times.


// Space Complexity: O(V^2) or O(n^2)
// Reason: Due to storing the adjacency matrix of the given graph.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
};

int main() {
	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);

	// Output: The answer is node: 3
	cout << "The answer is node: " << cityNo << endl;
	return 0;
}