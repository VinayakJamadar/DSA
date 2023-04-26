// Topic : DP on Rectangles
// Problem : Count Square Submatrices with All Ones

// Method 1 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and m iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*m) (i.e O(n) = O(1)+O(n*m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> mat{
        {0, 1, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0}
    };
    int n = mat.size(), m = mat[0].size();

    // Step 1. Create matrix 'dp' of same size of matrix 'mat'
    vector<vector<int>> dp(n, vector<int> (m, 0));
    
    // Step 2. Copy first row of matrix 'mat' into first row of matrix 'dp'
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = mat[0][j];
    }
    
    // Step 3. Copy first column of matrix 'mat' into first column of matrix 'dp'
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = mat[i][0];
    }
    
    // Step 4. 
    // For dp[1...n][1...m]
    // If mat[i][j] == 0 then dp[i][j] = 0;
    // Else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(mat[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
        }
    }
    
    // Step 5. Sum of matrix 'dp' is Count Square Submatrices with All Ones
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += dp[i][j];
        }
    }
    
    cout<<"Count Square Submatrices with All Ones : "<<sum<<endl;
    return 0;
}