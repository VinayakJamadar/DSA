// Topic : Introduction to DP
// Problem : Finding nth Fibonacci Number(were n is 0 indexed).

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n)
// Reason : As we are using a For Loop of n iterations


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(n) = O(1)+O(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<"Fibonacci("<<n<<") : "<<dp[n];
    return 0;
}