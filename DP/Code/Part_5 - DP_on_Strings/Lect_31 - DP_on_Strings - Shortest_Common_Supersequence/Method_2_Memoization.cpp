// Topic : DP on Strings
// Problem : Shortest Common Supersequence


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*m)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*m values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j])


// Auxilliary Space Complexity : O(n+m)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n+m) + O(n*m)
// Reason : Sum of Auxilliary Space Complexity O(n+m) and Non-Auxilliary Space Complexity O(n*m)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
    // Base Case
    if(i <= 0 or j <= 0) return 0;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]) {
        return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
    }
    return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}

int main()
{
    string s = "brute", t = "groot";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    int len = f(n, m, s, t, dp);

    string str = "";

    int i = n, j = m;

    while(i > 0 and j > 0) {
        if(s[i-1] == t[j-1]) {
            str += s[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            str += s[i-1];
            i--;
        }
        else {
            str += t[j-1];
            j--;
        }
    }

    while(i > 0) {
        str += s[i-1];
        i--;
    }

    while(j > 0) {
        str += t[j-1];
        j--;
    }

    reverse(str.begin(), str.end());
    cout<<"Shortest Common Supersequence : "<<str;
    return 0;
}