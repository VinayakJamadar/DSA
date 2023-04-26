// Topic : Partition DP
// Problem : Matrix Chain Multiplication

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*n*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*n values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j]) and also using for loop of n size.
// So overall time complexity is O(n*n*n)


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*n)
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*n)

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(i == j) return 0;
    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<"Answer : "<<f(1, n-1, arr, dp);
    return 0;
}