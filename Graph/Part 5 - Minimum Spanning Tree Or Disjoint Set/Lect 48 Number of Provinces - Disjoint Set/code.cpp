// Problem: Number of Provinces - Disjoint Set
// Article Link: https://takeuforward.org/data-structure/number-of-provinces-disjoint-set-g-48/


// V = Number of Vertices


// Time Complexity: O(V^2) + O(V * 4α) ~ O(V^2)
// Reason: O(V^2) for visiting the adjacency matrix and O(V) for the counting of ultimate parents. 4α is so small that this term can be ignored.


// Space Complexity: O(2N)
// Reason: O(2V) for the two arrays parent and size(or rank) of size V.


#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j]) ds.unionBySize(i, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (ds.findUPar(i) == i) cnt++;
        }
        return cnt;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    Solution obj;
    int ans = obj.numProvinces(adj, V);

    // Output: The number of provinces is: 2
    cout << "The number of provinces is: " << ans << endl;
    return 0;
}