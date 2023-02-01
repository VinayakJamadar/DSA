// Topic : DP on Subsequences
// Problem : 0/1 Knapsack


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*max(n, maxW/minElementOf(wt)))
// Reason : As we are using two nested For Loops (n and maxW+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(maxW+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(maxW+1))
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*(maxW+1)) (i.e O(n*(maxW+1)) = O(1)+O(n*(maxW+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> wt{2, 4, 6}, val{5, 11, 13};
    int n = wt.size(), maxW = 10;
    vector<vector<int>> dp(n, vector<int> (maxW+1, -1));

    for (int ind = 0; ind < n; ind++)
    {
        for (int w = 0; w < maxW+1; w++)
        {
            // Base Case
            if(ind == 0){
                if(w%wt[ind] == 0) dp[ind][w] = (w/wt[ind])*val[ind];
                else dp[ind][w] = INT_MIN;
            }
            // Recursive Case
            else {
                int notPick = 0 + dp[ind-1][w];
                int pick = INT_MIN;
                if(wt[ind] <= w) {
                    pick = val[ind] + dp[ind][w-wt[ind]];
                }
                dp[ind][w] = max(pick, notPick);
            }
        }
    }
    
    cout<<"Answer : "<<dp[n-1][maxW];
    return 0;
}