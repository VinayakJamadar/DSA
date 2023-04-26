// Topic : DP on Grids
// Problem : Unique Paths

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(m * n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only m * n values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxiliary Space Complexity : O(m + n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (m, n))

// Non-Auxiliary Space Complexity : O(m * n)
// Reason : using of vector data structure

// Total Space Complexity : O(m + n) + O(m * n)
// Reason : Sum of Auxiliary Space Complexity O(m + n) and Non-Auxiliary Space Complexity O(m * n)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& dp) {
    // Base Case
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j, dp);
    int left = f(i, j-1, dp);
    return dp[i][j] = up+left;
}

int main()
{
    int m = 3, n = 7;
    vector<vector<int>> dp(m, vector<int> (n, -1));
    cout<<"Unique Paths : "<<f(m-1, n-1, dp)<<endl;
    return 0;
}