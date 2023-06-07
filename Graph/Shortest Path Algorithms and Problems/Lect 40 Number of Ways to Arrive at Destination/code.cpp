// Problem: Number of Ways to Arrive at Destination
// Article Link: https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/


// n = Number of Nodes
// m = Number of Edges


// Time Complexity: O(m * log(n))
// Reason: As we are using simple Dijkstra’s algorithm here, the time complexity will be of the order m*log(n)


// Space Complexity: O(n) + O(n) + O(n + m) ~ O(n + m)
// Reason: for O(n) 'distTo' array, O(n) for 'ways' array and O(n + m) at max approximate complexity for priority queue


// Approach: Simple Dijsktra's Algorithm with Maintaining the number of ways to reach a node using 'ways' vector.


// Note:
// 1. Take long long for storing the time and infinite as 1e12. Reason: Check the Problem Constraints properly.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        // Creating an adjacency list for the given graph.
        vector<pair<int, long long>> adj[n];
        for (auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        // Initializing the 'distTo' array and the ways array
        // along with their first indices.
        vector<long long> distTo(n, 1e12);
        vector<int> ways(n, 0);
        distTo[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = 1e9 + 7;

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                // This 'if' condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (dist + edgeW < distTo[adjNode]) {
                    distTo[adjNode] = dist + edgeW;
                    pq.push({dist + edgeW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dist + edgeW == distTo[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};

int main() {
    // Driver Code.
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;
    int ans = obj.countPaths(n, edges);

    // Output: 4
    cout << ans << endl;

    return 0;
}