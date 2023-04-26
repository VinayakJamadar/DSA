// Topic : DP on LIS
// Problem : Number of Longest Increasing Subsequence

// Method 1 : Using Weird Algorithm Method (Updation of Tabulation) (Bottom-Up DP --> Base Cases to Recursive Cases)

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
    vector<int> arr{50, 3, 90, 60, 80};
    int n = arr.size();

    vector<int> dp(n, 1), cnt(n, 1);

    int maxLen = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if(arr[ind] > arr[prev]) {
                if(1+dp[prev] > dp[ind]) {
                    dp[ind] = 1+dp[prev];
                    cnt[ind] = cnt[prev];
                }
                else if(1+dp[prev] == dp[ind]) {
                    cnt[ind] += cnt[prev];
                }
            }
        }
        maxLen = max(maxLen, dp[ind]);
    }

    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i] == maxLen) nos += cnt[i];
    }

    cout<<nos<<endl;
    return 0;
}