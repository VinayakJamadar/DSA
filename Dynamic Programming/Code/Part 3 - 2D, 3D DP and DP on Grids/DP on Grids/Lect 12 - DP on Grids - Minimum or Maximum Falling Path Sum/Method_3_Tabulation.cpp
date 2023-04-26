// Topic : DP on Grids
// Problem : Maximum Path Sum in the matrix

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with m iterations.


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*m) (i.e O(n*m) = O(1)+O(n*m))

#include <bits/stdc++.h>
using namespace std;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(i == 0) dp[i][j] = matrix[i][j];
            // Recursive Case
            else {
                int up = dp[i-1][j];
                int leftDiagonal = INT_MIN;
                if(j-1 >= 0) leftDiagonal = dp[i-1][j-1];
                int rightDiagonal = INT_MIN;
                if(j+1 < m) rightDiagonal = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
            }
        }
    }

    int ans = INT_MIN;
    for (int k = 0; k < m; k++)
    {
        ans = max(ans, dp[n-1][k]);
    }
    
    cout<<"Maximum Path Sum in the matrix : "<<ans;
    return 0;
}