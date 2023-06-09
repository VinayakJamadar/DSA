// Problem: Disjoint Set - Union by Size
// Article Link: https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/


// V = Number of Nodes
// E = Number of Edges


// Time Complexity: O(4a); Where a = alpha
// Reason: The time complexity is O(4a) which is very small and close to 1.


// Space Complexity: O(V) + O(V)
// Reason: O(V) for 'rank' vector and O(V) for 'parent' vector


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

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // check if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    // check if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";
    return 0;
}