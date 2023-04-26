// Topic : DP on Stocks
// Problem : Buy and Sell Stock II


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*2)
// Reason : As we are using two nested For Loops (n and 2 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*2)
// Reason : Using of vector of vector data structure of n*2 size

// Total Space Complexity : O(n*2)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*2) (i.e O(n*2) = O(1)+O(n*2))

// Answer :
// Maximum Profit : 7

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : To simplify Base Case we shifted dp index by 1 (i.e n to n+1)

int main()
{
    vector<int> prices {7 ,1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, -1));

    // Base Case
    dp[n][0] = 0, dp[n][1] = 0;
    
    // Recursive Case
    for (int ind = n-1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int pick = 0, notPick = 0;
            // Buy
            if(buy) {
                pick = - prices[ind] + dp[ind+1][0];
                notPick = 0 + dp[ind+1][1];
            }
            // Sell
            else {
                pick = prices[ind] + dp[ind+1][1];
                notPick = 0 + dp[ind+1][0];
            }
            dp[ind][buy] = max(pick, notPick);
        }
    }
    
    cout<<"Maximum Profit : "<<dp[0][1]<<endl;
    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}