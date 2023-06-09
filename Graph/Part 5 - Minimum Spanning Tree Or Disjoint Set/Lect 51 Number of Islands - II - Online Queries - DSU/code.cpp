// Problem: Number of Islands - II - Online Queries - DSU
// Article Link: https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/


// N = Number of rows
// M = Number of columns
// Q = number of queries


// Time Complexity: O(Q * 4a) ~ O(Q)
// Reason: O(Q * 4a) for using a 'for' loop with Disjoint set operation which takes O(4a) is so small that it can be considered constant.


// Space Complexity: O(Q) + O(N*M) + O(N*M) 
// Reason: 
// 1. O(Q) for 'ans' vector
// 2. O(N * M) + O(N * M) the 'parent' and the 'size' vector used inside the Disjoint set data structure


#include <bits/stdc++.h>
using namespace std;

//User function Template for C++
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
private:
    bool isValid(int nr, int nc, int n, int m) {
        return nr >= 0 && nr < n && nc >= 0 && nc < m;
    }
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);

        int vis[n][m];
        memset(vis, 0, sizeof vis);

        int cnt = 0;
        vector<int> ans;
        
        for (auto it : operators) {
            int r = it[0];
            int c = it[1];

            if (vis[r][c] == 1) {
                ans.push_back(cnt);
                continue;
            }

            vis[r][c] = 1;
            cnt++;

            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            for (int ind = 0; ind < 4; ind++) {
                int nr = r + dr[ind];
                int nc = c + dc[ind];
                if (isValid(nr, nc, n, m) && vis[nr][nc]) {
                    int nodeNo = r * m + c;
                    int adjNodeNo = nr * m + nc;
                    if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);

    // Output: 1 1 2 1 1 2 2 2 3 3 1 1
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
