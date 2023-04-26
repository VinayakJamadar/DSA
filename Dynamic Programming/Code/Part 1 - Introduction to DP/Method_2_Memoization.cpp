// Topic : Introduction to DP
// Problem : Finding nth Fibonacci Number(were n is 0 indexed).

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n)
// Reason : As we avoided the overlapping subproblem. So mostly we have to calculate only n values (i.e calculating and storing the values in dp[n]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[n])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : using of vector data structure

// Total Space Complexity : O(n) + O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& dp) {
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp)+f(n-2, dp);
}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    cout<<"Fibonacci("<<n<<") : "<<f(n, dp);
    return 0;
}