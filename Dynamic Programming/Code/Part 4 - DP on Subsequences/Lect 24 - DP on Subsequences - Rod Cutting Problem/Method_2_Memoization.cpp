// Topic : DP on Subsequences
// Problem : Rod Cutting Problem


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(n+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(n+1) values (i.e calculating and storing the values in dp[ind][len]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][len])


// Auxiliary Space Complexity : O(max(n, minElementOf(arr)))
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(n+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(max(n, minElementOf(arr))) + O(n*(n+1))
// Reason : Sum of Auxiliary Space Complexity O(max(n, minElementOf(arr))) and Non-Auxiliary Space Complexity O(n*(n+1))


// Output :
// Answer : 12

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int len, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) return len*arr[ind];

    // Recursive Case
    if(dp[ind][len] != -1) return dp[ind][len];
    int notPick = 0 + f(ind-1, len, arr, dp);
    int pick = INT_MIN;
    if(ind+1 <= len) {
        pick = arr[ind] + f(ind, len-(ind+1), arr, dp);
    }
    return dp[ind][len] = max(pick, notPick);
}

int main()
{
    vector<int> arr{2, 5, 7, 8, 10};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    
    cout<<"Answer : "<<f(n-1, n, arr, dp);
    return 0;
}