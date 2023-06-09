// Problem: Making a Large Island - DSU
// Article Link: https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/


// N = Number of rows or columns


// Time Complexity: O(N^2)+O(N^2) ~ O(N^2) 
// Reason: O(N^2) for two nested 'for' loops, all the operations of DisjointSet are taking apparently constant time.


// Space Complexity: O(2 * N^2)
// Reason: for the two arrays i.e. 'parent' array and 'size' array of size N^2 inside the Disjoint set.


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
private:
    bool isValid(int nr, int nc, int n) {
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DisjointSet ds(n * n);

        int vis[n][n];
        memset(vis, 0, sizeof vis);

        // int cnt = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c]) {
                    vis[r][c] = 1;

                    for (int ind = 0; ind < 4; ind++) {
                        int nr = r + dr[ind];
                        int nc = c + dc[ind];
                        if (isValid(nr, nc, n) && vis[nr][nc]) {
                            int nodeNo = r * n + c;
                            int adjNodeNo = nr * n + nc;
                            if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                                ds.unionBySize(nodeNo, adjNodeNo);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        // To handle the case if all cells of grid is 1
        for(int i = 0; i < n*n; i++) {
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0) {
                    // To handle the case if adjacent cells belongs to same components
                    set<int> components;
                    for (int ind = 0; ind < 4; ind++) {
                        int nr = r + dr[ind];
                        int nc = c + dc[ind];
                        if (isValid(nr, nc, n) && grid[nr][nc]) {
                            components.insert(ds.findUPar(nr * n + nc));
                        }
                    }
                    int cnt = 0;
                    for(auto it: components) {
                        cnt += ds.size[it];
                    }
                    ans = max(ans, cnt + 1);
                }
            }
        }

        return ans;
    }
};


int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, 
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, 
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, 
        {0, 0, 1, 1, 1, 0}
    };

    Solution obj;
    int ans = obj.MaxConnection(grid);

    // Output: The largest group of connected 1's is of size: 20
    cout << "The largest group of connected 1's is of size: " << ans << endl;
    return 0;
}