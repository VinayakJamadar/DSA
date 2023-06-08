// Problem: Course Schedule I
// Link: https://leetcode.com/problems/course-schedule/

// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)
// 3. Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0

// Time Complexity: O(V + E)
// Reason: Time complexity of Detect a Cycle in DAG by topological sort using bfs traversal (i.e. Kahn's Algorithm)

// Space Complexity: O(2V)
// Reason: Space taken 'indegree' vector and 'q' queue.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<int> adj[V];
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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

        if(topo.size() == V) return true;
        return false;
	}
};

int main() {
	vector<vector<int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	Solution obj;
	bool ans = obj.canFinish(N, prerequisites);

    // Answer: YES
	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl;

	return 0;
}