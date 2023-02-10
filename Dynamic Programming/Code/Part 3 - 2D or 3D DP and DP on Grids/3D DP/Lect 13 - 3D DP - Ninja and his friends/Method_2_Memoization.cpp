// Topic : 3D DP
// Problem : Ninja and his friends

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*m*m*9)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*m*m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(n*m*m)
// Reason : using of vector data structure

// Total Space Complexity : O(n) + O(n*m*m)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*m*m)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& matrix, vector<vector<vector<int>>>& dp) {
    // Base Case
    if((j1 < 0 or j1 >= m) or (j2 < 0 or j2 >= m)) return INT_MIN;
    if(i == n-1) {
        if(j1 == j2) return matrix[i][j1];
        else return matrix[i][j1] + matrix[i][j2];
    }
    
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    // Recursive Case
    int maxi = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if((j1+dj1) == (j2+dj2)) value = matrix[i][j1] + f(i+1, j1+dj1, j2+dj2, n, m, matrix, dp);
            else value = matrix[i][j1] + matrix[i][j2] + f(i+1, j1+dj1, j2+dj2, n, m, matrix, dp);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int main()
{
    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    cout<<"Answer : "<<f(0, 0, m-1, n, m, matrix, dp);
    return 0;
}