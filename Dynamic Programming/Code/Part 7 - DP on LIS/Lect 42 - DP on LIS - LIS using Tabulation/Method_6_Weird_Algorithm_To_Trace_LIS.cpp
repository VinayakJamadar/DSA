// Topic : DP on LIS
// Problem : Print Longest Increasing Subsequence and its Length

// Method 6 : Using Weird Algorithm Method to Trace(or Print) LIS (Bottom-Up DP --> Base Cases to Recursive Cases)

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

// IMPORTANT NOTE : Here we used Backtracking using hash array for Weird Method to Trace(or Print) LIS

int main()
{
    vector<int> arr{5, 4, 11, 1, 16, 8};
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    int maxLen = 1, lastInd = 0;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if(arr[ind] > arr[prev]) {
                if(1+dp[prev] > dp[ind]) {
                    dp[ind] = 1+dp[prev];
                    hash[ind] = prev;
                }
            }
        }

        if(dp[ind] > maxLen) {
            maxLen = dp[ind];
            lastInd = ind;
        }
    }

    vector<int> lis(maxLen);
    lis[maxLen-1] = arr[lastInd];
    for (int i = 1; i < maxLen; i++)
    {
        lastInd = hash[lastInd];
        lis[maxLen-1-i] = arr[lastInd];
    }

    cout<<"LIS : [ ";
    for (int i = 0; i < maxLen; i++)
    {
        cout<<lis[i]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Length of LIS : "<<maxLen<<endl;
    return 0;
}