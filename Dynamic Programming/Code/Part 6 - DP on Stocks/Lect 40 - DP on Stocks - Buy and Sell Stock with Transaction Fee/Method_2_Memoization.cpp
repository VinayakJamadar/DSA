// Topic : DP on Stocks
// Problem : Buy and Sell Stock with Transaction Fee


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*2)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*2 values (i.e calculating and storing the values in dp[ind][buy]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][buy])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*2)
// Reason : Using of vector of vector data structure of n*2 size

// Total Space Complexity : O(n) + O(n*2)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*2)

// Answer :
// Maximum Profit : 3

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int>& prices,int fee, vector<vector<int>>& dp) {
    // Base Case
    if(ind == prices.size()) return 0;

    // Recursive Case
    if(dp[ind][buy] != -1) return dp[ind][buy];
    int pick = 0, notPick = 0;
    // Buy
    if(buy) {
        pick = - prices[ind] + f(ind+1, 0, prices, fee, dp);
        notPick = 0 + f(ind+1, 1, prices, fee, dp);
    }
    // Sell
    else {
        pick = prices[ind] - fee + f(ind+1, 1, prices, fee, dp);
        notPick = 0 + f(ind+1, 0, prices, fee, dp);
    }
    return dp[ind][buy] = max(pick, notPick);
}

int main()
{
    vector<int> prices{1, 3, 5, 6};
    int n = prices.size(), fee = 2;
    vector<vector<int>> dp(n, vector<int> (2, -1));
    
    cout<<"Maximum Profit : "<<f(0, 1, prices, fee, dp)<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}