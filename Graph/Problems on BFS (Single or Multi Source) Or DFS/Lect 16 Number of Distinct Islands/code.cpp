// Problem: Number of Distinct Islands

// Problem Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Article Link: https://takeuforward.org/data-structure/number-of-distinct-islands/

// N = Number of Nodes
// M = Number of Edges

// Time Complexity: O(N x M x log(N x M)) + O(N x M x 4) ~ O(N x M)
// Reason: For the worst case, assuming all the pieces as land, the DFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, it will take O(N x M x 4) time. Set at max will store the complete grid, so it takes log(N x M) time.

// Space Complexity: O(N x M) + O(N x M) ~ O(N x M) 
// Reason: For the visited array and set takes up N x M locations at max. 

// Notes:
// 1. This problem can be solved using both DFS and BFS just follow the same adjecent nodes direction order.

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int r, int c, int R, int C, int n, int m, vector<pair<int, int>>& vec, vector<vector<int>>& vis, vector<int>& dr, vector<int>& dc, vector<vector<int>>& grid) {
        // mark the cell as visited
        vis[r][c] = 1;

        // coordinates - base coordinates
        // r - R
        // c - C
        vec.push_back({r - R, c - C});

        int nr, nc;
        // traverse all 4 neighbours
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            // check for valid unvisited land neighbour coordinates
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, R, C, n, m, vec, vis, dr, dc, grid);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        // dr and dc
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, -1, 0, +1};

        // traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if not visited and is a land cell
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, i, j, n, m, vec, vis, dr, dc, grid);
                    // store in set
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    Solution obj;
    // Output: 3
    cout << obj.countDistinctIslands(grid) << endl;
}