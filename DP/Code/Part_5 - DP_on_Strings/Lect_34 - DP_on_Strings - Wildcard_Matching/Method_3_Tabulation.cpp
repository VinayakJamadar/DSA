// Topic : DP on Strings
// Problem : Longest Common Subsequence


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*m) (i.e O(n*m) = O(1)+O(n*m))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : With Index Shifting

int main()
{
    string pattern = "ba*a?", text = "baaabab";
    int n = pattern.size(), m = text.size();
    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            // Base Case
            if(i == 0 and j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(j == 0) {
                bool flag = true;
                for (int k = 1; k <= i; k++)
                {
                    if(pattern[k-1] != '*') {
                        flag = false;
                        break;
                    }
                }
                dp[i][j] = flag;
            }
            // Recursive Case
            else {
                if(pattern[i-1] == text[j-1] or pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else {
                    if(pattern[i-1] == '*') {
                        dp[i][j] = dp[i-1][j] or dp[i][j-1];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
    }
    
    cout<<"Answer : "<<(dp[n][m] ? "true" : "false");
    return 0;
}