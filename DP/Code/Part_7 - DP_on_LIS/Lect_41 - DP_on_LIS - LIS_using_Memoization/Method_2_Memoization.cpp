// Topic : DP on LIS
// Problem : Length of Longest Increasing Subsequence

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(n+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(n+1) values (i.e calculating and storing the values in dp[ind][prev_ind]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][prev_ind])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(n+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*(n+1))
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*(n+1))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : As prev_ind has value from -1 to n-1 and -1 is not be used as ind. So we are using Coordinate Change
// Coordinate Change:
// prev_ind (Before Coordinate Change) : -1, 0, 1, 2, 3, 4, ... , n-1
// prev_ind (After Coordinate Change) :   0, 1, 2, 3, 4, 5, ... , n

int f(int ind, int prev_ind, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(ind == arr.size()) return 0;
    // Recursive Case
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    int notPick = 0 + f(ind+1, prev_ind, arr, dp);
    int pick = 0;
    if(prev_ind == 0 or (prev_ind != 0 and arr[ind] > arr[prev_ind-1])) pick = 1 + f(ind+1, ind+1, arr, dp);
    return dp[ind][prev_ind+1] = max(notPick, pick);
}

int main()
{
    vector<int> arr{10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));

    cout<<"Answer : "<<f(0, 0, arr, dp);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n+1; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}