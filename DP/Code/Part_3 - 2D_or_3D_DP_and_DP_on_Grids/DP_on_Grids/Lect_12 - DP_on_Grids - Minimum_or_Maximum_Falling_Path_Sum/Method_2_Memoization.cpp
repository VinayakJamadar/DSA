// Topic : DP on Grids
// Problem : Maximum Path Sum in the matrix

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*m)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, 0))

// Non-Auxilliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n) + O(n*m)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*m)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    // Base Case
    if(j < 0 or j >= matrix[0].size()) return INT_MIN;
    if(i == 0) return matrix[0][j];

    if(dp[i][j] != -1) return dp[i][j];
    // Recursive Case
    int up = f(i-1, j, matrix, dp);
    int leftDiagonal = f(i-1, j-1, matrix, dp);
    int rightDiagonal = f(i-1, j+1, matrix, dp);
    return dp[i][j] = matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp (n, vector<int> (m, -1));

    int ans = INT_MIN;
    for (int k = 0; k < m; k++)
    {
        ans = max(ans, f(n-1, k, matrix, dp));
    }
    cout<<"Maximum Path Sum in the matrix : "<<ans;
    return 0;
}