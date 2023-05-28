#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        //Function to find the shortest distance of all the vertices
        //from the source vertex S.
        vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
            // Initialising 'distTo' list with a large number to
            // indicate the nodes are unvisited initially.
            // This list contains distance from source to the nodes.
            vector<int> distTo(V, INT_MAX);

            // Create a priority queue for storing the nodes as a pair {dist,node}
            // where 'dist' is the distance from source to the node node.
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

            // Source initialised with distance d=0.
            distTo[S] = 0;
            pq.push({0, S});

            // Now, pop the minimum distance node first from the min-heap
            // and traverse for all its adjacent nodes.
            int dist, node, v, w;
            while(!pq.empty()) {
                dist = pq.top().first;
                node = pq.top().second;
                pq.pop();

                // Check for all adjacent nodes of the popped out
                // element whether the prev dist is larger than current or not.
                for(auto i: adj[node]) {
                    v = i[0];
                    w = i[1];

                    // If current distance is smaller,
                    // push it into the queue.
                    if(dist + w < distTo[v]) {
                        distTo[v] = dist + w;
                        pq.push({dist + w, v});
                    }
                }
            }
            // Return the list containing shortest distances
            // from source to all the nodes.
            return distTo;
        }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> vs;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}