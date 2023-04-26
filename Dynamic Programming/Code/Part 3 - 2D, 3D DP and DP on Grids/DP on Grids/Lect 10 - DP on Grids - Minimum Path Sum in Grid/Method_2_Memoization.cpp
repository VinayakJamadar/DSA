// Topic : DP on Grids
// Problem : Minimum Path Sum in Grid

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n * m)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n * m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxiliary Space Complexity : O(n + m)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, m))

// Non-Auxiliary Space Complexity : O(n * m)
// Reason : using of vector data structure

// Total Space Complexity : O(n + m) + O(n * m)
// Reason : Sum of Auxiliary Space Complexity O(n + m) and Non-Auxiliary Space Complexity O(n * m)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base Case
    if(i == 0 and j == 0) return grid[0][0];
    if(i < 0 or j < 0) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];
    // Recursive Case
    int up = f(i-1, j, grid, dp);
    int left = f(i, j-1, grid, dp);
    return dp[i][j] = grid[i][j] + min(up, left);
}

int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<"Minimum Path Sum in Grid : "<<f(n-1, m-1, grid, dp);
    return 0;
}