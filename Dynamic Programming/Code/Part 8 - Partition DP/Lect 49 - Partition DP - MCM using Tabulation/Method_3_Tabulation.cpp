// Topic : Partition DP
// Problem : Matrix Chain Multiplication

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n*n)
// Reason : As we are using three nested For Loops (n, n and n iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*n)
// Reason : Using of vector of vector data structure of n*n size

// Total Space Complexity : O(n*n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*n) (i.e O(n*n) = O(1)+O(n*n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            // Base Case
            if(i == j) dp[i][j] = 0;
            // Recursive Case
            else {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
    }
    
    cout<<"Answer : "<<dp[1][n-1];
    return 0;
}