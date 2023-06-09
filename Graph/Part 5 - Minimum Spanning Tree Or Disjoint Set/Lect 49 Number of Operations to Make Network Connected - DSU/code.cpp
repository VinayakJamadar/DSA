// Problem: Number of Operations to Make Network Connected - DSU
// Article Link: https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/


// V = Number of Vertices
// E = Number of Edges


// Time Complexity: O(E * 4a) + O(V * 4a) ~ O(E + V) 
// Reason:
// 1. O(E * 4a) to calculate the number of extra edges
// 2. O(V * 4a) to count the number of components
// 4a is for the disjoint set operation we have used and this term is so small that it can be considered constant.


// Space Complexity: O(2V)
// Reason: O(2V) for the two arrays(parent and size) of size V used inside the disjoint set.


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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};

int main() {
    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    Solution obj;
    int ans = obj.Solve(V, edge);

    // Output: The minimum number of operations needed: 2
    cout << "The minimum number of operations needed: " << ans << endl;
    return 0;
}
