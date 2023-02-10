// Topic : Partition DP
// Problem : Burst Balloons


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O((n+2)*(n+2)*n)
// Reason : As we are using three nested For Loops (n+2, n+2 and n iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O((n+2)*(n+2))
// Reason : Using of vector of vector data structure of n*n size

// Total Space Complexity : O((n+2)*(n+2))
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O((n+2)*(n+2)) (i.e O((n+2)*(n+2)) = O(1)+O((n+2)*(n+2)))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE :

// 1. Reason for inserting 1 at front
// To get the previous balloon size for first element

// 2. Reason for inserting 2 at back
// To get the next balloon size for last element

int main()
{
    vector<int> a{7, 1, 8};
    int n = a.size();
    // Inserting 1 at front
	a.insert(a.begin(), 1);
    // Inserting 1 at back
	a.push_back(1);
    
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    for (int i = n; i >= 1; i--)
    {
        // handled Base Case in loops
        for (int j = i; j <= n; j++)
        {
            // Recursive Case
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int coins = (a[i-1]*a[k]*a[j+1]) + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;
        }
    }
    
    cout<<"Answer"<<dp[1][n];
    return 0;
}