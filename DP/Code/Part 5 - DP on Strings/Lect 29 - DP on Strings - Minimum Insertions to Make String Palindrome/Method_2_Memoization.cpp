// Topic : DP on Strings
// Problem : Minimum Insertions to Make String Palindrome


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxilliary Space Complexity : O(2n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(2n)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(2n) + O(n*n)
// Reason : Sum of Auxilliary Space Complexity O(2n) and Non-Auxilliary Space Complexity O(n*n)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
    // Base Case
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
    return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}

int main()
{
    string s = "bbbab", t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    
    cout<<"Answer : "<<n - f(n-1, n-1, s, t, dp);
    return 0;
}