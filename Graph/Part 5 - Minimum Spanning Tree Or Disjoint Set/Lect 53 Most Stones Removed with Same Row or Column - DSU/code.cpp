// Problem: Most Stones Removed with Same Row or Column - DSU
// Article Link: https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/


// N = Number of stones


// Time Complexity: O(N)
// Reason: Here we have just traversed the given stones array several times. And inside those loops, every operation is apparently taking constant time. So, the time complexity is only the time of traversal of the array.


// Space Complexity: O(2 * (maxRow + maxColumn)) 
// Reason: O(maxRow + maxColumn) for the 'parent' and 'size' vectors inside the Disjoint Set data structure.


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class DisjointSet {
public:
    vector<int> size, parent;
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};

    Solution obj;
    int ans = obj.maxRemove(stones, n);

    // Output: The maximum number of stones we can remove is: 4
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}