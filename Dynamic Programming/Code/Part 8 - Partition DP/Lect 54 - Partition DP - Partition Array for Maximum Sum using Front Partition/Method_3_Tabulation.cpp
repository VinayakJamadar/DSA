// Topic : Partition DP
// Problem : Partition Array for Maximum Sum using Front Partition

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*k)
// Reason : As we are using two nested For Loops (n and k iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(n) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 15, 7, 9, 2, 5, 10};
    int n = arr.size(), k = 3;
    vector<int> dp(n+1, -1);
    // Base Case
    dp[n] = 0;
    // Recursive Case
    for (int i = n-1; i >= 0; i--)
    {
        int maxSum = INT_MIN, len = 0, maxElem = INT_MIN;
        for (int j = i; j < min(n, i+k); j++)
        {
            len++;
            maxElem = max(maxElem, arr[j]);
            int sum = (maxElem*len) + dp[j+1];
            maxSum = max(maxSum, sum);
        }
        dp[i] = maxSum;
    }
    
    cout<<"Answer : "<<dp[0];
    return 0;
}