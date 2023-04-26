// Topic : DP on Stocks
// Problem : Buy and Sell Stock IV


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*2*k)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*4 values (i.e calculating and storing the values in dp[ind][transaction]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][transaction])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*2*k)
// Reason : Using of vector of vector data structure of n*2*k size

// Total Space Complexity : O(n) + O(n*2*k)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*2*k)

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int transaction, vector<int>& prices, int n, int k, vector<vector<int>>& dp) {
    // Base Case
    if(transaction == 2*k) return 0;
    if(ind == n) return 0;

    // Recursive Case
    if(dp[ind][transaction] != -1) return dp[ind][transaction];
    int pick = 0, notPick = 0;
    // Buy
    if(transaction % 2 == 0) {
        pick = - prices[ind] + f(ind+1, transaction+1, prices, n, k, dp);
        notPick = 0 + f(ind+1, transaction, prices, n, k, dp);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+1, transaction+1, prices, n, k, dp);
        notPick = 0 + f(ind+1, transaction, prices, n, k, dp);
    }
    return dp[ind][transaction] = max(pick, notPick);
}

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size(), k = 2;
    vector<vector<int>> dp(n, vector<int> (2*k, -1));
    
    cout<<"Maximum Profit : "<<f(0, 0, prices, n, k, dp)<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < cnt; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}