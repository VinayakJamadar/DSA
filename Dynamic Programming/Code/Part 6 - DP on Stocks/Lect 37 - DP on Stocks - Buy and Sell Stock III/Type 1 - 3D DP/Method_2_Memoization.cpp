// Topic : DP on Stocks
// Problem : Buy and Sell Stock III


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*2*3)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*2*3 values (i.e calculating and storing the values in dp[ind][buy][cap]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][buy][cap])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*2*3)
// Reason : Using of vector of vector data structure of n*2*3 size

// Total Space Complexity : O(n) + O(n*2*3)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*2*3)

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
    // Base Case
    if(cap == 0) return 0;
    if(ind == prices.size()) return 0;

    // Recursive Case
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    int pick = 0, notPick = 0;
    // Buy
    if(buy) {
        pick = - prices[ind] + f(ind+1, 0, cap, prices, dp);
        notPick = 0 + f(ind+1, 1, cap, prices, dp);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+1, 1, cap-1, prices, dp);
        notPick = 0 + f(ind+1, 0, cap, prices, dp);
    }
    return dp[ind][buy][cap] = max(pick, notPick);
}

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size(), cnt = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (cnt+1, -1)));
    
    cout<<"Maximum Profit : "<<f(0, 1, cnt, prices, dp);
    return 0;
}