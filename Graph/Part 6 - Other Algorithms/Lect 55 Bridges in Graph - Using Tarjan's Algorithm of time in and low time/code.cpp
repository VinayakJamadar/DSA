// Problem: Bridges in Graph - Using Tarjan's Algorithm of time in and low time
// Article Link: https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/


// Bridge:
// Any edge in a component of a graph is called a bridge when the component is divided into 2 or more components if we remove that particular edge.


// Intuition

// DFS with Time of Insertion and Lowest Time of Insertion

// Time of Insertion(tin[]): Dring the DFS call, the time when a node is visited, is called its time of insertion. For example, if in the above graph, we start DFS from node 1 it will visit node 1 first then node 2, node 3, node 4, and so on. So, the time of insertion for node 1 will be 1, node 2 will be 2, node 3 will be 3 and it will continue like this. To store the time of insertion for each node, we will use a time array.

// Lowest Time of Insertion(low[]): In this case, the current node refers to all its adjacent nodes except the parent and takes the minimum lowest time of insertion into account. To store this entity for each node, we will use another 'low' array.


// The logical modification of the DFS algorithm is discussed below:

// After the DFS for any adjacent node gets completed, we will just check if the edge, whose starting point is the current node and ending point is that adjacent node, is a bridge. For that, we will just check if any other path from the current node to the adjacent node exists if we remove that particular edge. If any other alternative path exists, this edge is not a bridge. Otherwise, it can be considered a valid bridge. 


// Approach: 

// The algorithm steps are as follows:

// 1. First, we need to create the adjacency list for the given graph from the edge information(If not already given). And we will declare a variable timer(either globally or we can carry it while calling DFS), that will keep track of the time of insertion for each node.
// 2. Then we will start DFS from node 0(assuming the graph contains a single component otherwise, we will call DFS for every component) with parent -1.
    // 2.i. Inside DFS, we will first mark the node visited and then store the time of insertion and the lowest time of insertion properly. The timer may be initialized to 0 or 1.
    // 2.ii. Now, it's time to visit the adjacent nodes. 
        // 2.ii.a. If the adjacent node is the parent itself, we will just continue to the next node.
        // 2.ii.b. If the adjacent node is not visited, we will call DFS for the adjacent node with the current node as the parent.
            // After the DFS gets completed, we will compare the lowest time of insertion of the current node and the adjacent node and take the minimum one.
            // Now, we will check if the lowest time of insertion of the adjacent node is greater than the time of insertion of the current node.
            // If it is, then we will store the adjacent node and the current node in our answer array as they are representing the bridge.
    // 2.iii. If the adjacent node is already visited, we will just compare the lowest time of insertion of the current node and the adjacent node and take the minimum one.
// 3. Finally, our 'ans' array will store all the bridges.


// Note: 
// 1. We are not considering the parent's insertion time during calculating the lowest insertion time as we want to check if any other path from the node to the parent exists excluding the edge we intend to remove.


// V = Number of Vertices
// E = Number of Edges


// Time Complexity: O(V+2E)
// Reason: O(V + 2E) for DFS traversal.


// Space Complexity: O(V+2E) + O(3V)
// Reason: 
// 1. O(V+2E) to store the graph in an adjacency list
// 2. O(3V) for the three arrays i.e. tin, low, and vis, each of size V.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};

int main() {

    int n = 12;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {3, 4}, {4, 5}, {5, 7}, {5, 8}, {6, 7}, {7, 8}, {7, 9}, {8, 6}, {9, 10}, {10, 11}, {11, 9}};

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    // Output:
    // [9, 7]
    // [5, 4]
    // [4, 3]
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "]" << endl;
    }
    cout << endl;
    return 0;
}