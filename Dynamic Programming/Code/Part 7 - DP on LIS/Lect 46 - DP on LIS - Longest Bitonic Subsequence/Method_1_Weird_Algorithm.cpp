// Topic : DP on LIS
// Problem : Length of Longest Bitonic Sequence

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

// IMPORTANT DEFINITION : 
// 1. Bitonic Subsequence : 
// A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:
// a. First, increase till a point and then decrease.
// b. Goes on increasing (Longest increasing subsequence)
// c. Goes on decreasing (Longest decreasing subsequence)

// STEPS : 
// 1. Find Length of LIS of arr from FRONT(i.e Storing in frontDp)
// 2. Find Length of LIS of arr from BACK(i.e Storing in backDp)
// 3. Then Length of Longest Bitonic Subsequence is frontDp[i]+backDp[i]-1

int main()
{
    vector<int> arr{2, 1, 3, 1};
    int n = arr.size();

    vector<int> frontDp(n, 1), backDp(n, 1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if(arr[ind] > arr[prev]) {
                frontDp[ind] = max(frontDp[ind], 1+frontDp[prev]);
            }
        }
    }

    // reverse the direction of nested loops for finding length of LIS of arr from Backward
    for (int ind = n-1; ind >= 0; ind--)
    {
        for (int prev = n-1; prev > ind; prev--)
        {
            if(arr[ind] > arr[prev]) {
                backDp[ind] = max(backDp[ind], 1+backDp[prev]);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, frontDp[i]+backDp[i]-1);
    }

    cout<<"Length of Longest Bitonic Subsequence is : "<<maxLen<<endl;
    return 0;
}