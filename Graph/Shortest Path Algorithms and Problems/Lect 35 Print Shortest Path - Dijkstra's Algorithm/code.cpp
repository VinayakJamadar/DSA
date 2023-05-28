#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        int u, v, w;
        for(auto i: edges) {
            u = i[0];
            v = i[1];
            w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> distTo(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        distTo[1] = 0;
        parent[1] = 1;
        pq.push({0, 1});
        
        int dist, node;
        while(!pq.empty()) {
            dist = pq.top().first;
            node = pq.top().second;
            pq.pop();

            for(auto i: adj[node]) {
                v = i.first;
                w = i.second;

                if(dist + w < distTo[v]) {
                    distTo[v] = dist + w;
                    parent[v] = node;
                    pq.push({dist + w, v});
                }
            }
        }
        
        if(distTo[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int dst = n;
        while(parent[dst] != dst) {
            path.push_back(dst);
            dst = parent[dst];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

int main()
{
    // Driver code.
    int V = 5, E = 6;

    vector<vector<int>> edges;
    edges.push_back({1, 2, 2});
    edges.push_back({2, 5, 5});
    edges.push_back({2, 3, 4});
    edges.push_back({1, 4, 1});
    edges.push_back({4, 3, 3});
    edges.push_back({3, 5, 1});

    Solution obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}