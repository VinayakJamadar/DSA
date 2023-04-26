// Topic : DP on Grids
// Problem : Minimum Path Sum in Grid

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * m)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with m iterations.


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n * m)
// Reason : Using of vector of vector data structure of n * m size

// Total Space Complexity : O(n * m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n * m) (i.e O(n * m) = O(1)+O(n * m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(i == 0 and j == 0) dp[0][0] = grid[0][0];
            // Recursive Case
            else {
                int up = INT_MAX, left = INT_MAX;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    
    cout<<"Minimum Path Sum in Grid : "<<dp[n-1][m-1]<<endl;
    return 0;
}