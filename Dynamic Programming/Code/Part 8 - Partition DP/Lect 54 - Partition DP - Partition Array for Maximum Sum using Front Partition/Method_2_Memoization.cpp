// Topic : Partition DP
// Problem : Partition Array for Maximum Sum using Front Partition

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*k)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*k values (i.e calculating and storing the values in dp[i]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using of vector data structure

// Total Space Complexity : O(n) + O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, int n, vector<int>& arr, vector<int>& dp) {
    // Base Case
    if(i == n) return 0;
    // Recursive Case
    if(dp[i] != -1) return dp[i];
    int maxSum = INT_MIN, len = 0, maxElem = INT_MIN;
    for (int j = i; j < min(n, i+k); j++)
    {
        len++;
        maxElem = max(maxElem, arr[j]);
        int sum = (maxElem*len) + f(j+1, k, n, arr, dp);
        maxSum = max(maxSum, sum);
    }
    return dp[i] = maxSum;
}

int main()
{
    vector<int> arr{1, 15, 7, 9, 2, 5, 10};
    int n = arr.size(), k = 3;
    vector<int> dp(n, -1);
    cout<<"Answer : "<<f(0, k, n, arr, dp);
    return 0;
}