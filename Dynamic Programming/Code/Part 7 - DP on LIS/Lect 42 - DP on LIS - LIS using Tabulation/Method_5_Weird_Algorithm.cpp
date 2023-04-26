// Topic : DP on LIS
// Problem : Length of Longest Increasing Subsequence

// Method 5 : Using Weird Algorithm Method (Updation of Tabulation) (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n) (i.e O(1) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    vector<int> dp(n, 1);

    int maxLen = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if(arr[ind] > arr[prev]) {
                dp[ind] = max(dp[ind], 1+dp[prev]);
            }
        }
        maxLen = max(maxLen, dp[ind]);
    }

    cout<<maxLen<<endl;
    return 0;
}