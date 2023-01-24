// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(maxTarget+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(maxW+1) values (i.e calculating and storing the values in dp[ind][target]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][target])


// Auxilliary Space Complexity : O(max(n, k)) , where k = reqTarget/minElementOf(coins)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(maxTarget+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(max(n, k)) + O(n*(maxTarget+1)) , where k = reqTarget/minElementOf(coins)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*(maxTarget+1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) {
        if(target%coins[ind] == 0) return target/coins[ind];
        else return 1e9;
    }

    // Recursive Case
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = 0 + f(ind-1, target, coins, dp);
    int pick = INT_MAX;
    if(target >= coins[ind]) {
        pick = 1 + f(ind, target-coins[ind], coins, dp);
    }
    return dp[ind][target] = min(pick, notPick);
}

int main()
{
    vector<int> coins{1, 6, 5, 9};
    int n = coins.size(), reqTarget = 11;
    vector<vector<int>> dp(n, vector<int> (reqTarget+1, -1));

    int ans = f(n-1, reqTarget, coins, dp);
    if(ans >= 1e9) cout<<"Answer : -1";
    else cout<<"Answer : "<<ans;
    return 0;
}