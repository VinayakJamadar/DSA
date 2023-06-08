// Problem: Bipartite Graph using BFS

// Definition of Bipartite Graph
// If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a Bipartite graph.

// Important Note
// 1. All acyclic graphs are bipartite.
// 2. For a cyclic graph
//      i. Bipartite if all its cycles are of even length
//      ii. Not Bipartite if any of its cycle is of odd length

// V = Number of Nodes
// E = Number of Edges

// Time Complexity: O(V + 2E)
// Reason: Time complexity of bfs traversal of undirected graph

// Space Complexity: O(V)
// Reason: Space taken 'color' vector.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int node, vector<int>& color, vector<int> adj[]) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()) {
            node = q.front();
            q.pop();
            for(auto i: adj[node]) {
                // If the adjacent node is yet not colored
                // then give the opposite color of the node
                if(color[i] == -1) {
                    color[i] = !color[node];
                    q.push(i);
                }
                // else if the adjacent guy having the same color
                // someone did color it from different path
                // i.e we got a odd cycle
                else if(color[i] == color[node]) return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);

        // for connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (bfs(i, color, adj) == false) return false;
            }
        }
        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    // V = 4, E = 4
    vector<int> adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipartite(4, adj);
    if (ans) cout << "Graph is Bipartite Graph" << endl;
    else cout << "Graph is not Bipartite Graph" << endl;
    return 0;
}