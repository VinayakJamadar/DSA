// Topic : DP on LIS
// Problem : Print Longest Divisible Subset

// Method 1 : Using Weird Algorithm Method to Trace(or Print) LIS (Bottom-Up DP --> Base Cases to Recursive Cases)

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

// IMPORTANT DEFINITION : 
// 1. Subset : In a subsequence, the elements need to follow the order of the original array whereas in a subset there is no constraint on the order of the elements.
// 2. Divisible Subset : A divisible subset is the one in which if we pick any two index i and j from the subset, then either arr[i]%arr[j] == 0 or arr[j] % arr[i] == 0. For example, [16,8,4] is a divisible subset.

// STEPS : 
// As here we are finding the subsets, we can change the order of the original array. 
// So first sort the given array. 
// Then if we find Longest Divisible Subsequence it will give Longest Divisible Subset of given array.
// For Finding Longest Divisible Subsequence we will use 'Method_6_Weird_Algorithm_To_Trace_LIS' of 'Lect_42 - DP_on_LIS - Longest_Increasing_Subsequence_using_Tabulation'
// But rather than comparing for largest number we will compare for divisibility

int main()
{
    vector<int> arr{1, 16, 7, 8, 4};
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    int maxLen = 1, lasti = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if(arr[i] % arr[j] == 0) {
                if(1+dp[j] > dp[i]) {
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
        }

        if(dp[i] > maxLen) {
            maxLen = dp[i];
            lasti = i;
        }
    }

    vector<int> lis(maxLen);
    lis[maxLen-1] = arr[lasti];
    for (int i = 1; i < maxLen; i++)
    {
        lasti = hash[lasti];
        lis[maxLen-1-i] = arr[lasti];
    }

    cout<<"Longest Divisible Subset : [ ";
    for (int i = 0; i < maxLen; i++)
    {
        cout<<lis[i]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Length of Longest Divisible Subset : "<<maxLen<<endl;
    return 0;
}