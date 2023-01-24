// Topic : DP on Grids
// Problem : Unique Paths

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(m * n)
// Reason : As we are using two nested For Loops. Outer For Loop with m iterations and Inner For Loop with n iterations.

// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(m * n)
// Reason : Using of vector of vector data structure of m * n size

// Total Space Complexity : O(m * n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(m * n) (i.e O(m * n) = O(1)+O(m * n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3, n = 7;
    vector<vector<int>> dp(m, vector<int> (n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Base Case
            if(i == 0 and j == 0) dp[0][0] = 1;
            // Recursive Case
            else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    cout<<"Unique Paths : "<<dp[m-1][n-1]<<endl;
    return 0;
}