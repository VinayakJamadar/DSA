// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(maxTarget+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(maxW+1) values (i.e calculating and storing the values in dp[ind][target]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][target])


// Auxiliary Space Complexity : O(max(n, k)) , where k = reqTarget/minElementOf(coins)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(maxTarget+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(max(n, k)) + O(n*(maxTarget+1)) , where k = reqTarget/minElementOf(coins)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*(maxTarget+1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) {
        if(target%coins[ind] == 0) return 1;
        else return 0;
    }

    // Recursive Case
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = f(ind-1, target, coins, dp);
    int pick = 0;
    if(target >= coins[ind]) {
        pick = f(ind, target-coins[ind], coins, dp);
    }
    return dp[ind][target] = notPick + pick;
}

int main()
{
    vector<int> coins{1, 2, 3};
    int n = coins.size(), reqTarget = 4;
    vector<vector<int>> dp(n, vector<int> (reqTarget+1, -1));
    
    cout<<f(n-1, reqTarget, coins, dp);
    return 0;
}