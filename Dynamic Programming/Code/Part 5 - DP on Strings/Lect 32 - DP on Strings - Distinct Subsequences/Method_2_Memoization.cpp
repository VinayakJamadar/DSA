// Topic : DP on Strings
// Problem : Distinct Subsequences


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

// With Index Shifting

#define mod 1000000007;

int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    // Base Case
    if(j == 0) return 1;
    if(i == 0) return 0;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]) {
        return dp[i][j] = (f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp)) % mod;
    }
    else return dp[i][j] = f(i-1, j, s, t, dp);
}

int main()
{
    string s = "babgbag", t = "bag";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    cout<<"Answer : "<<f(n, m, s, t, dp)<<endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // Without Index Shifting

// #define mod 1000000007;

// int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//     // Base Case
//     if(j < 0) return 1;
//     if(i < 0) return 0;

//     // Recursive Case
//     if(dp[i][j] != -1) return dp[i][j];
//     if(s[i] == t[j]) {
//         return dp[i][j] = (f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp)) %mod;
//     }
//     else return dp[i][j] = f(i-1, j, s, t, dp);
// }

// int main()
// {
//     string s = "babgbag", t = "bag";
//     int n = s.size(), m = t.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
    
//     cout<<"Answer : "<<f(n-1, m-1, s, t, dp)<<endl;
//     return 0;
// }