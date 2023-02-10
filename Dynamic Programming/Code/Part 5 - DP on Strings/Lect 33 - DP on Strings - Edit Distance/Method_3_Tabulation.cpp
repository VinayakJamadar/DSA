// Topic : DP on Strings
// Problem : Edit Distance


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*m) (i.e O(n*m) = O(1)+O(n*m))


// Answer : 5

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : With Index Shifting

int main()
{
    string s = "intention", t = "execution";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            // Base Case
            if(i == 0 or j == 0) {
                if(i == 0) dp[i][j] = j;
                else dp[i][j] = i;
            }
            // Recursive Case
            else {
                if(s[i-1] == t[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else {
                    // 1. Insert
                    int insert = dp[i][j-1];
                    // 2. Remove
                    int remove = dp[i-1][j];
                    // 3. Replace
                    int replace = dp[i-1][j-1];

                    dp[i][j] = 1 + min(insert, min(remove, replace));
                }
            }
        }
    }
    
    cout<<"Answer : "<<dp[n][m];
    return 0;
}