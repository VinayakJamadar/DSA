// Topic : DP on Strings
// Problem : Distinct Subsequences


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

// With Index Shifting

#define mod 1000000007;

int main()
{
    string s = "babgbag", t = "bag";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    // Base Case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // Recursive Case
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"Answer : "<<dp[n][m];
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// Without Index Shifting

#define mod 1000000007;

int main()
{
    string s = "babgbag", t = "bag";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(j == 0) {
                if(i == 0) dp[i][0] = (s[i] == t[0]);
                else dp[i][0] = (s[i] == t[0]) + dp[i-1][0];
            }
            // Recursive Case
            else if(i > 0) {
                if(s[i] == t[j]) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    cout<<"Answer : "<<dp[n-1][m-1];
    return 0;
}