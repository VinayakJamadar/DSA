// Topic : DP on Strings
// Problem : Longest Palindromic Subsequence


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*n)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*n) (i.e O(n*n) = O(1)+O(n*n))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : We have not done the Index Shifting. So Code is different than Striver

int main()
{
    string s = "bbbab", t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Base Case
            if(s[i] == t[j]) {
                if(i == 0 or j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + dp[i-1][j-1];
            }
            // Recursive Case
            else {
                if(i == 0 or j == 0) {
                    if(i == 0 and j == 0) dp[i][j] = 0;
                    else if(j == 0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout<<"Answer : "<<dp[n-1][n-1];
    return 0;
}