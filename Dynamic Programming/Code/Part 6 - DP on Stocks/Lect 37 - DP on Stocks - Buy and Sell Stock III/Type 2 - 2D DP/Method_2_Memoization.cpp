// Topic : DP on Stocks
// Problem : Buy and Sell Stock III


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*4)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*4 values (i.e calculating and storing the values in dp[ind][transaction]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][transaction])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*4)
// Reason : Using of vector of vector data structure of n*4 size

// Total Space Complexity : O(n) + O(n*4)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*4)

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int transaction, vector<int>& prices, vector<vector<int>>& dp) {
    // Base Case
    if(transaction == 4) return 0;
    if(ind == prices.size()) return 0;

    // Recursive Case
    if(dp[ind][transaction] != -1) return dp[ind][transaction];
    int pick = 0, notPick = 0;
    // Buy
    if(transaction % 2 == 0) {
        pick = - prices[ind] + f(ind+1, transaction+1, prices, dp);
        notPick = 0 + f(ind+1, transaction, prices, dp);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+1, transaction+1, prices, dp);
        notPick = 0 + f(ind+1, transaction, prices, dp);
    }
    return dp[ind][transaction] = max(pick, notPick);
}

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (4, -1));
    
    cout<<"Maximum Profit : "<<f(0, 0, prices, dp)<<endl;
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