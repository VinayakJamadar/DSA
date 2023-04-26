// Topic : DP on LIS
// Problem : Length of Longest Increasing Subsequence

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(n+1))
// Reason : As we are using two nested For Loops (n and n+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(n+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(n+1))
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(n+1)) (i.e O(n*(n+1)) = O(1)+O(n*(n+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int prev_ind = ind; prev_ind >= 0; prev_ind--) {
            int notPick = 0 + dp[ind+1][prev_ind];
            int pick = 0;
            if(prev_ind == 0 or (prev_ind != 0 and arr[ind] > arr[prev_ind-1])) pick = 1 + dp[ind+1][ind+1];
            dp[ind][prev_ind] = max(notPick, pick);
        }
    }
    
    cout<<"Answer : "<<dp[0][0];

    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < n+1; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}