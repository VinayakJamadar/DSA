// Topic : DP on Stocks
// Problem : Buy and Sell Stock III


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*4)
// Reason : As we are using two nested For Loops (n and 4 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*4)
// Reason : Using of vector of vector data structure of n*4 size

// Total Space Complexity : O(n*4)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*4) (i.e O(n*4) = O(1)+O(n*4))

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : To simplify Base Case we shifted dp ind by 1 (i.e n to n+1), transaction by 1 (i.e 4 to 5)

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (4+1, -1));

    for (int ind = n; ind >= 0; ind--)
    {
        for (int transaction = 4; transaction >= 0; transaction--)
        {
            // Base Case
            if(ind == n) dp[ind][transaction] = 0;
            // Base Case
            else if(transaction == 4) dp[ind][transaction] = 0;
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