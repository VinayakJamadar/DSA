// Problem: Print Shortest Path - Dijkstra's Algorithm
// Article Link: https://takeuforward.org/data-structure/g-35-print-shortest-path-dijkstras-algorithm/


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(E * log(V)) + O(V) ~ O(E * log(V))
// Reason: O(n) for Dijkstra’s Algorithm and O(V) for backtracking in order to find the parent for each node.


// Space Complexity: O(E + V) + O(V) ~ O(E + V)
// Reason: O(E + V) for priority queue and dist array and O(V) for storing the final path.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        // Create an adjacency list of pairs of the form node1 -> {node2, edge weight}
        // where the edge weight is the weight of the edge from node1 to node2.
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Create a priority queue for storing the nodes along with distances 
        // in the form of a pair { dist, node }.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        // Create a distTo array for storing the updated distances and a parent array
        //for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.
        vector<int> distTo(n + 1, 1e9), parent(n + 1);

        for (int i = 1; i <= n; i++) parent[i] = i;

        distTo[1] = 0;

        // Push the source node to the queue.
        pq.push({0, 1});
        while (!pq.empty()) {
            // Topmost element of the priority queue is with minimum distance value.
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dist = it.first;

            // Iterate through the adjacent nodes of the current popped node.
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                // Check if the previously stored distance value is 
                // greater than the current computed value or not, 
                // if yes then update the distance value.
                if (dist + edgeW < distTo[adjNode]) {
                    distTo[adjNode] = dist + edgeW;
                    pq.push({dist + edgeW, adjNode});

                    // Update the parent of the adjNode to the recent 
                    // node where it came from.
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (distTo[n] == 1e9) return {-1};

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        // Since the path stored is in a reverse order, we reverse the array
        // to get the final answer and then return the array.
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    // Driver Code
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    // Output :
    // 1 4 3 5
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}