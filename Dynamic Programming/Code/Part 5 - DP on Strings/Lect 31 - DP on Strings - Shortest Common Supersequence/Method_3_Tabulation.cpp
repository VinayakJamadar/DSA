// Topic : DP on Strings
// Problem : Shortest Common Supersequence


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*m)
// Reason : Using of vector of vector data structure of n*m size

// Total Space Complexity : O(n*m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*m) (i.e O(n*m) = O(1)+O(n*m))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : We have done the Index Shifting in dp table.

int main()
{
    string s = "brute", t = "groot";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
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