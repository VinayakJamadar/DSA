// Topic : DP on Strings
// Problem : Edit Distance


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


// Answer : 5

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : With Index Shifting

int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    // Base Case
    if(i == 0) return j;
    if(j == 0) return i;

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]) return dp[i][j] = 0 + f(i-1, j-1, s, t, dp);
    else {
        // 1. Insert
        int insert = f(i, j-1, s, t, dp);
        // 2. Remove
        int remove = f(i-1, j, s, t, dp);
        // 3. Replace
        int replace = f(i-1, j-1, s, t, dp);

        return dp[i][j] = 1 + min(insert, min(remove, replace));
    }
}

int main()
{
    string s = "intention", t = "execution";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    cout<<"Answer : "<<f(n, m, s, t, dp);
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // IMPORTANT NOTE : Without Index Shifting

// int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//     // Base Case
//     if(i < 0) return j+1;
//     if(j < 0) return i+1;

//     // Recursive Case
//     if(dp[i][j] != -1) return dp[i][j];
//     if(s[i] == t[j]) return dp[i][j] = 0 + f(i-1, j-1, s, t, dp);
//     else {
//         // 1. Insert
//         int insert = f(i, j-1, s, t, dp);
//         // 2. Remove
//         int remove = f(i-1, j, s, t, dp);
//         // 3. Replace
//         int replace = f(i-1, j-1, s, t, dp);

//         return dp[i][j] = 1 + min(insert, min(remove, replace));
//     }
// }

// int main()
// {
//     string s = "intention", t = "execution";
//     int n = s.size(), m = t.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
    
//     cout<<"Answer : "<<f(n-1, m-1, s, t, dp);
//     return 0;
// }