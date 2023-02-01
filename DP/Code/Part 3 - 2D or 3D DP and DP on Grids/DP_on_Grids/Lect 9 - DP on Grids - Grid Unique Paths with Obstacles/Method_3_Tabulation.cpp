// Topic : DP on Grids
// Problem : Unique Paths with Obstacles

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * m)
// Reason : As we are using nested For Loops.

// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree).

// Non-Auxilliary Space Complexity : O(n * m)
// Reason : Using of vector of vector data structure of m * n size.

// Total Space Complexity : O(n * m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n * m) (i.e O(n * m) = O(1)+O(n * m)).

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    int n = maze.size(), m = maze[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(maze[i][j] == -1) dp[i][j] = 0;
            // Base Case
            else if(i == 0 and j == 0) dp[0][0] = 1;
            // Recursive Case
            else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = (up+left)%mod;
            }
        }
    }
    
    cout<<"Unique Paths with Obstacles : "<<dp[n-1][m-1]<<endl;
    return 0;
}