// Problem: Number of Provinces


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(V + 2E)
// Reason: Time complexity of dfs traversal of undirected graph


// Space Complexity: O(V)
// Reason: Space taken 'vis' vector.


// Notes:
// 1. This problem can be solved using both DFS and BFS.
// 2. In this code we used DFS.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], vector<bool>& vis) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        
        vector<bool> vis(V, 0);
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
                dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
    }
};

int main() {
    vector<vector<int>> adj {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Output: 2
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
    return 0;
}