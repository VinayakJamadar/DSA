// Topic : Partition DP
// Problem : Burst Balloons

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O((n+2)*(n+2)*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only (n+2)*(n+2) values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j]) and also using for loop of n size.
// So overall time complexity is O((n+2)*(n+2)*n)


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O((n+2)*(n+2))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O((n+2)*(n+2))
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O((n+2)*(n+2))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : 

// 1. Reason for inserting 1 at front
// To get the previous balloon size for first element

// 2. Reason for inserting 2 at back
// To get the next balloon size for last element

int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
    // Base Case
    if(i > j) return 0;
    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int coins = (a[i-1]*a[k]*a[j+1]) + f(i, k-1, a, dp) + f(k+1, j, a, dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}

int main()
{
    vector<int> a{7, 1, 8};
    int n = a.size();
    // Inserting 1 at front
	a.insert(a.begin(), 1);
    // Inserting 1 at back
	a.push_back(1);

    vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
    cout<<"Answer"<<f(1, n, a, dp);
    return 0;
}