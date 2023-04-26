// Topic : DP on Subsequences
// Problem : 0/1 Knapsack

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(maxW+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(maxW+1) values (i.e calculating and storing the values in dp[ind][target]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][target])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(maxW+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*(maxW+1))
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*(maxW+1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0){
        if(wt[ind] <= w) {
            return val[ind];
        }
        else return 0;
    }

    // Recursive Case
    if(dp[ind][w] != -1) return dp[ind][w];
    int notPick = 0 + f(ind-1, w, wt, val, dp);
    int pick = INT_MIN;
    if(wt[ind] <= w) {
        pick = val[ind] + f(ind-1, w-wt[ind], wt, val, dp);
    }
    return dp[ind][w] = max(pick, notPick);
}

int main()
{
    vector<int> wt{1, 2, 4, 5}, val{5, 4, 8, 6};
    int n = wt.size(), maxW = 5;
    vector<vector<int>> dp(n, vector<int> (maxW+1, -1));

    cout<<"Answer : "<<f(n-1, maxW, wt, val, dp);
    return 0;
}