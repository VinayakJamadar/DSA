// Topic : DP on Strings
// Problem : Print Longest Common Subsequence


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*m)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxiliary Space Complexity : O(n+m)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n+m) + O(n*m)
// Reason : Sum of Auxiliary Space Complexity O(n+m) and Non-Auxiliary Space Complexity O(n*m)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
    // Base Case
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) {
        return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
    }
    return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}

int main()
{
    string s = "acd", t = "ced";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    int len = f(n-1, m-1, s, t, dp);
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