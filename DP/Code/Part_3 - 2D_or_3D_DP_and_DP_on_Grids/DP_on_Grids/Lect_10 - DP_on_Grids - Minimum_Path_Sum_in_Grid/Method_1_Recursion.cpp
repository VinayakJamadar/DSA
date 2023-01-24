// Topic : DP on Grids
// Problem : Minimum Path Sum in Grid

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2 ^ max(n , m))
// Reason : As we are calling 2 recursive calls { i.e up = f(i-1, j) and left = f(i, j-1) } for max(n , m) times


// Auxilliary Space Complexity : O(n + m)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, m))

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n + m)
// Reason : Sum of Auxilliary Space Complexity O(n + m) and Non-Auxilliary Space Complexity O(1) (i.e O(n + m) = O(n + m) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& grid) {
    // Base Case
    if(i == 0 and j == 0) return grid[0][0];
    if(i < 0 or j < 0) return INT_MAX;

    // Recursive Case
    int up = f(i-1, j, grid);
    int left = f(i, j-1, grid);
    return grid[i][j] + min(up, left);
}

int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    int n = grid.size(), m = grid[0].size();
    cout<<"Unique Paths with Obstacles : "<<f(n-1, m-1, grid);
    return 0;
}