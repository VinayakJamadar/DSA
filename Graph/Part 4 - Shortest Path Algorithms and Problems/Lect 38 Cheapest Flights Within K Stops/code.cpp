// Problem: Cheapest Flights Within K Stops
// Article Link: https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/


// V = n = Number of vertices
// E = m = Number of edges


// Time Complexity: O(E) ~ O(m)
// Reason: As dijsktra's algorithm takes O(E * log(V)) i.e O(m * log (n)). But log(n) of time eliminated here because we're using a simple queue rather than a priority queue.


// Space Complexity: O(E + V) ~ O(m + n)
// Reason: O(E) i.e O(m) for 'q' queue and O(V) i.e O(n) for 'distTo' vector


// Approach: Dijsktra's Algorithm using Queue


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        // Create the adjacency list to depict airports and flights in
        // the form of a graph.
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, cost}} with 'stops' indicating 
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Distance array to store the updated distances from the source.
        vector<int> distTo(n, 1e9);
        distTo[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with 
        // popping out the element with min stops first.
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop the process as soon as the limit for the stops reaches.
            if (stops > K) continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.
                if (cost + edgeW < distTo[adjNode] && stops <= K) {
                    distTo[adjNode] = cost + edgeW;
                    q.push({stops + 1, {adjNode, cost + edgeW}});
                }
            }
        }

        // If the destination node is unreachable return ‘-1’
        // else return the calculated dist from src to dst.
        if (distTo[dst] == 1e9) return -1;
        return distTo[dst];
    }
};

int main(){
    // Driver Code.
    int n = 5, src = 0, dst = 2, K = 2;

    vector<vector<int>> flights = {{0, 1, 5}, {0, 3, 2}, {1, 2, 5}, {1, 4, 1}, {3, 1, 2}, {4, 2, 1}};

    Solution obj;
    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    // Output: 7
    cout << ans << endl;

    return 0;
}