// Topic : DP on Strings
// Problem : Longest Common Substring


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*m) (i.e O(n*k) = O(1)+O(n*m))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : We have not done the Index Shifting. So Code is different than Striver

int main()
{
    string s = "abcdef", t = "abzdefy";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(s[i] == t[j]) {
                if(i == 0 or j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + dp[i-1][j-1];
                len = max(len, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    cout<<"Length of longest common substring is : "<<len;
    return 0;
}