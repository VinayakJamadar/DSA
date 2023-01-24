// Topic : DP on Strings
// Problem : Print Longest Common Subsequence


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

// IMPORTANT NOTE : We have not done the Index Shifting. So Code is different than Striver

int main()
{
    string s = "acd", t = "ced";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
    
    int len = dp[n-1][m-1];
    string lcs = "";
    for (int i = 0; i < len; i++)
    {
        lcs += '$';
    }

    int i = n-1, j = m-1, index = len-1;
    while(i >= 0 and j >= 0) {
        if(s[i] == t[j]) {
            lcs[index] = s[i];
            i--, j--, index--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout<<"Lcs is : "<<lcs<<" and length of lcs is : "<<len;
    return 0;
}