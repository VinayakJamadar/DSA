// Problem: Course Schedule II
// Link: https://leetcode.com/problems/course-schedule-ii/

// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)
// 3. Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0

// Time Complexity: O(V + E)
// Reason: Time complexity of topological sort using bfs traversal (i.e. Kahn's Algorithm) in directed graph

// Space Complexity: O(2V)
// Reason: Space taken 'indegree' vector and 'q' queue.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}

		vector<int> indegree(V, 0);
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

		if (topo.size() == V) return topo;
		return {};
	}
};

int main() {
	int N = 4;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	vector<int> ans = obj.findOrder(N, prerequisites);

    // Answer: 3 2 1 0
	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}