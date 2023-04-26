// Topic : DP on Subsequences
// Problem : 0/1 Knapsack


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(maxW+1))
// Reason : As we are using two nested For Loops (n and maxW+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(maxW+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(maxW+1))
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(maxW+1)) (i.e O(n*(maxW+1)) = O(1)+O(n*(maxW+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> wt{1, 2, 4, 5}, val{5, 4, 8, 6};
    int n = wt.size(), maxW = 5;
    vector<vector<int>> dp(n, vector<int> (maxW+1, -1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int w = 0; w < maxW+1; w++)
        {
            // Base Case
            if(ind == 0) {
                if(wt[ind] <= w) {
                    dp[ind][w] = val[0];
                }
                else dp[ind][w] = 0;
            }
            else {
                // Recursive Case
                int notPick = 0 + dp[ind-1][w];
                int pick = INT_MIN;
                if(wt[ind] <= w) {
                    pick = val[ind] + dp[ind-1][w-wt[ind]];
                }
                dp[ind][w] = max(pick, notPick);
            }
        }
    }
    
    cout<<"Answer : "<<dp[n-1][maxW];
    return 0;
}