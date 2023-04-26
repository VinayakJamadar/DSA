// Topic : DP on Subsequences
// Problem : Rod Cutting Problem


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(n+1))
// Reason : As we are using two nested For Loops (n and n+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(n+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(n+1))
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(n+1)) (i.e O(n*(n+1)) = O(1)+O(n*(n+1)))


// Output :
// Answer : 12

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{2, 5, 7, 8, 10};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    
    for (int ind = 0; ind < n; ind++)
    {
        for (int len = 0; len < n+1; len++)
        {
            // Base Case
            if(ind == 0) dp[ind][len] = len*arr[ind];
            // Recursive Case
            else {
                int notPick = 0 + dp[ind-1][len];
                int pick = INT_MIN;
                if(ind+1 <= len) {
                    pick = arr[ind] + dp[ind][len-(ind+1)];
                }
                dp[ind][len] = max(pick, notPick);
            }
        }
    }

    cout<<"Answer : "<<dp[n-1][n];
    return 0;
}