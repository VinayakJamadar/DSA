// Topic : DP on LIS
// Problem : Length of Longest String Chain of Subset

// Method 5 : Using Weird Algorithm Method (Updation of Tabulation) (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n*len(maxSizeElement(arr)))
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
// 1. Subset or Sequence : In a subsequence, the elements need to follow the order of the original array whereas in a subset there is no constraint on the order of the elements.
// 2. String Chain : 
// Let’s say a string ‘A’ is a predecessor of string ‘B’ if and only if we can add exactly one letter anywhere in ‘A’ to make it equal to ‘B’. For example “abd” is a predecessor of “abcd”, we can add “c” in “abd” to make a string “abcd”
// A string chain is a sequence of strings where for every ‘i’ in [1 . . . (K - 1)], ‘S[i]’ is the predecessor of ‘S[i+1]’. And the length of such a string chain is ‘K’.

// STEPS : 
// As here we are finding the subsets, we can change the order of the original array. 
// So first sort the given array according to length. 
// Then if we find Longest String Chain Subsequence it will give Longest String Chain of Subset of given array.
// For Finding Longest String Chain Subsequence we will use 'Method_5_Weird_Algorithm' of 'Lect_42 - DP_on_LIS - Longest_Increasing_Subsequence_using_Tabulation'. 
// But rather than comparing for largest number we will use checkPossible function which will return true is string ‘A’ is a predecessor of string ‘B’ if and only if we can add exactly one letter anywhere


bool checkPossible(string &a, string &b) {
    if(a.size() != b.size()+1) return 0;
    else {
        int i = 0, j = 0;
        while(i < a.size()) {
            if(j < b.size() and a[i] == b[j]) ++i, ++j;
            else ++i;
        }
        return (i == a.size() and j == b.size());
    }
}

int main()
{
    vector<string> arr{"a", "b", "ba", "bca", "bda", "bdca"};
    int n = arr.size();

    sort(arr.begin(), arr.end(), [](string a, string b) {
        return a.size() < b.size();
    });

    vector<int> dp(n, 1);

    int maxLen = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if(checkPossible(arr[ind], arr[prev])) {
                dp[ind] = max(dp[ind], 1+dp[prev]);
            }
        }
        maxLen = max(maxLen, dp[ind]);
    }

    cout<<"Length of Longest String Chain of Subset is : "<<maxLen<<endl;
    return 0;
}