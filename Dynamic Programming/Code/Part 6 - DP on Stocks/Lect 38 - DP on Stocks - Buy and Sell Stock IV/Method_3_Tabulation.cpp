// Topic : DP on Stocks
// Problem : Buy and Sell Stock IV


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*2*k)
// Reason : As we are using two nested For Loops (n and 4 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*2*k)
// Reason : Using of vector of vector data structure of n*2*k size

// Total Space Complexity : O(n*2*k)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*2*k) (i.e O(n*2*k) = O(1)+O(n*2*k))

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : To simplify Base Case we shifted dp ind by 1 (i.e n to n+1), transaction by 1 (i.e 2*k to 2*k+1)

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size(), k = 2;
    vector<vector<int>> dp(n+1, vector<int> (2*k+1, -1));

    for (int ind = n; ind >= 0; ind--)
    {
        for (int transaction = 2*k; transaction >= 0; transaction--)
        {
            // Base Case
            if(ind == n) dp[ind][transaction] = 0;
            // Base Case
            else if(transaction == 2*k) dp[ind][transaction] = 0;
            // Recursive Case
            else {
                int pick = 0, notPick = 0;
                // Buy
                if(transaction % 2 == 0) {
                    pick = - prices[ind] + dp[ind+1][transaction+1];
                    notPick = 0 + dp[ind+1][transaction];
                }
                // Sell
                else {
                    pick = prices[ind] + dp[ind+1][transaction+1];
                    notPick = 0 + dp[ind+1][transaction];
                }
                dp[ind][transaction] = max(pick, notPick);
            }
        }
    }
    
    cout<<"Maximum Profit : "<<dp[0][0]<<endl;
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