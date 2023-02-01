// Topic : DP on Strings
// Problem : Longest Common Subsequence


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

// IMPORTANT NOTE : With Index Shifting

bool f(int i, int j, string& pattern, string& text, vector<vector<int>>& dp) {
    // Base Case
    if(i == 0 and j == 0) return true;
    if(i == 0 and j > 0) return false;
    if(j == 0 and i > 0) {
        for (int k = 1; k <= i; k++)
        {
            if(pattern[k-1] != '*') return false;
        }
        return true;
    }

    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    if(pattern[i-1] == text[j-1] or pattern[i-1] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);
    else {
        if(pattern[i-1] == '*') {
            return dp[i][j] = f(i-1, j, pattern, text, dp) or f(i, j-1, pattern, text, dp);
        }
        else {
            return dp[i][j] = false;
        }
    }
}

int main()
{
    string pattern = "ba*a?", text = "baaabab";
    int n = pattern.size(), m = text.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    cout<<"Answer : "<<(f(n, m, pattern, text, dp) ? "true" : "false")<<endl;
    
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // IMPORTANT NOTE : Without Index Shifting

// bool f(int i, int j, string& pattern, string& text, vector<vector<int>>& dp) {
//     // Base Case
//     if(i < 0 and j < 0) return true;
//     if(i < 0 and j >= 0) return false;
//     if(j < 0 and i >= 0) {
//         for (int k = 0; k <= i; k++)
//         {
//             if(pattern[k] != '*') return false;
//         }
//         return true;
//     }

//     // Recursive Case
//     if(dp[i][j] != -1) return dp[i][j];
//     if(pattern[i] == text[j] or pattern[i] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);
//     else {
//         if(pattern[i] == '*') {
//             return dp[i][j] = f(i-1, j, pattern, text, dp) or f(i, j-1, pattern, text, dp);
//         }
//         else {
//             return dp[i][j] = false;
//         }
//     }
// }

// int main()
// {
//     string pattern = "ba*a?", text = "baaabab";
//     int n = pattern.size(), m = text.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
    
//     cout<<"Answer : "<<(f(n-1, m-1, pattern, text, dp) ? "true" : "false");
//     return 0;
// }