// Topic : DP on triangles
// Problem : Minimum path sum in Triangular Grid

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n * n values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, 0))

// Non-Auxilliary Space Complexity : O(n*n)
// Reason : Using vector data structure

// Total Space Complexity : O(n) + O(n*n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*n)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    // Base Case
    if(i == triangle.size()-1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];
    // Recursive Case
    int down = f(i+1, j, n, triangle, dp);
    int diagonal = f(i+1, j+1, n, triangle, dp);
    return dp[i][j] = triangle[i][j] + min(down, diagonal);
}

int main()
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<"Minimum path sum in Triangular Grid : "<<f(0, 0, n, triangle, dp);
    return 0;
}