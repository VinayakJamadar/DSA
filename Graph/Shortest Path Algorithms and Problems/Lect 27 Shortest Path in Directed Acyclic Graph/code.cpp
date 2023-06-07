// Problem: Shortest Path in Directed Acyclic Graph


// N = Number of Nodes
// M = Number of Edges


// Time Complexity: O(N + M) + O(N + M) ~ O(N + M)
// Reason: O(N + M) for the topological sort and O(N+M) for relaxation of vertices, each node and its adjacent nodes get traversed.


// Space Complexity: O(N) + O(N) + O(N) + O(N + 2M) ~ O(N + M)
// Reason: O(N) for the stack storing the topological sort, O(N) {for storing the shortest distance for each node, O(N) for the visited array and O(N+2M) for the adjacency list.


// Approach: Topological Sort


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // This is the function to implement Topological sort.
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // We create a graph first in the form of an adjacency list.
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        // A visited array is created with initially
        // all the nodes marked as unvisited (0).
        vector<int> vis(N, 0);

        // Step 1. Now, we perform topo sort using DFS technique and store the result in the stack st.
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 2. Further, we declare a vector ‘dist’ in which we update the value of the nodes distance from the source vertex after relaxation of a particular node.
        vector<int> dist(N, 1e9);
        
        // Here source node is '0'
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v]) {
                    dist[v] = wt + dist[node];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    int N = 6, M = 7;

    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    Solution obj;
    vector<int> ans = obj.shortestPath(N, M, edges);

    // Output: 0 2 3 6 1 5
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}