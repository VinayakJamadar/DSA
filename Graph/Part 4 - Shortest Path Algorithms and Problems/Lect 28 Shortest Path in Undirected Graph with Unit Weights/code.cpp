// Problem: Shortest Path in Undirected Graph with Unit Weights


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(M) + O(N + 2M) + O(N) ~ O(N + 2M)
// Reason: O(M) for creating the adjacency list from given list 'edges', O(N + 2M) for the BFS Algorithm, O(N) for adding the final values of the shortest path in the resultant array. 


// Space Complexity: O(N) + O(N) + O(N) + O(N + 2M) ~ O(N + M) 
// Reason: O(N) for the stack storing the BFS, O(N) for the resultant array, O(N) for the dist array storing updated shortest paths, O( N+2M) for the adjacency list.


// Approach: Simple BFS


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src) {
        //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.
        vector<int> dist(N, 1e9);

        // BFS Implementation.
        queue<int> q;
        q.push(src); 
        dist[src] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }

        // Unreachable nodes are marked as -1.
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        return dist; 
    }
};

int main() {
    int N = 9, M = 10;
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

    Solution obj;
    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    // Output: 
    // 0 1 2 1 2 3 3 4 4
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}