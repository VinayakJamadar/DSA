// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(maxTarget+1))
// Reason : As we are using two nested For Loops (n and maxTarget+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(maxTarget+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(maxTarget+1))
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*(maxTarget+1)) (i.e O(n*(maxTarget+1)) = O(1)+O(n*(maxTarget+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins{1, 6, 5, 9};
    int n = coins.size(), reqTarget = 11;
    vector<vector<int>> dp(n, vector<int> (reqTarget+1, -1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target < reqTarget+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target%coins[ind] == 0) dp[ind][target] = target/coins[ind];
                else dp[ind][target] = 1e9;
            }
            // Recursive Case
            else {
                int notPick = 0 + dp[ind-1][target];
                int pick = INT_MAX;
                if(target >= coins[ind]) {
                    pick = 1 + dp[ind][target-coins[ind]];
                }
                dp[ind][target] = min(pick, notPick);
            }
        }
    }
    
    int ans = dp[n-1][reqTarget];
    if(ans >= 1e9) cout<<"Answer : -1";
    else cout<<"Answer : "<<ans;
    return 0;
}