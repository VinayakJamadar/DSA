// Problem: Detect a Cycle in an Undirected Graph using DFS


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(V + 2E)
// Reason: Time complexity of dfs traversal of undirected graph


// Space Complexity: O(V)
// Reason: Space taken 'vis' vector.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        // visit adjacent nodes
        for (auto adjacentNode : adj[node]) {
            // unvisited adjacent node
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, vis, adj) == true) return true;
            }
            // visited node but not a parent node
            else if (adjacentNode != parent) return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        // for graph with connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj) == true) return true;
            }
        }
        return false;
    }
};

int main() {
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    
    Solution obj;
    bool ans = obj.isCycle(4, adj);

    // Output: 0
    if (ans) cout << "1\n";
    else cout << "0\n";
    return 0;
}