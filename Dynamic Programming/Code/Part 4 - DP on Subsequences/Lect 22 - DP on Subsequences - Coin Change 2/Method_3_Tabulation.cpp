// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(maxTarget+1))
// Reason : As we are using two nested For Loops (n and maxTarget+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(maxTarget+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(maxTarget+1))
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(maxTarget+1)) (i.e O(n*(maxTarget+1)) = O(1)+O(n*(maxTarget+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins{1, 2, 3};
    int n = coins.size(), reqTarget = 4;
    vector<vector<int>> dp(n, vector<int> (reqTarget+1, -1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target < reqTarget+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target%coins[ind] == 0) dp[ind][target] = 1;
                else dp[ind][target] = 0;
            }
            // Recursive Case
            else {
                int pick = 0;
                if(target >= coins[ind]) {
                    pick = dp[ind][target-coins[ind]];
                }
                int notPick = dp[ind-1][target];
                dp[ind][target] = notPick + pick;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < reqTarget+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<dp[n-1][reqTarget];
    return 0;
}