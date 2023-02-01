// Topic : Partition DP
// Problem : Burst Balloons

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*n*2*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*n*2 values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j]) and also using for loop of n size.
// So overall time complexity is O(n*n*2*n)


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*n*2)
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*n*2)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*n*2)

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll f(int i, int j, bool isTrue, string& exp, vector<vector<vector<ll>>>& dp) {
    // Base Case
    if(i == j) {
        if(isTrue) return (exp[i] == 'T');
        else return (exp[i] == 'F');
    }
    // Recursive Case
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    ll ways = 0;
    for (int k = i+1; k <= j-1; k+=2)
    {
        ll lT = f(i, k-1, 1, exp, dp); // leftTrue
        ll lF = f(i, k-1, 0, exp, dp); // leftFalse
        ll rT = f(k+1, j, 1, exp, dp); // rightTrue
        ll rF = f(k+1, j, 0, exp, dp); // rightFalse
        // For AND(&) operator
        // T&T = T, T&F = F, F&T = F, F&F = F
        if(exp[k] == '&') {
            if(isTrue) {
                ways = (ways + (lT * rT)%mod)%mod;
            }
            else {
                ways = (ways + (lF * rT)%mod + (lT * rF)%mod + (lF * rF)%mod)%mod;
            }
        }
        // For OR(|) operator
        // T|T = T, T|F = T, F|T = T, F|F = F
        else if(exp[k] == '|') {
            if(isTrue) {
                ways = (ways + (lT * rT)%mod + (lF * rT)%mod + (lT * rF)%mod)%mod;
            }
            else {
                ways = (ways + (lF * rF)%mod)%mod;
            }
        }
        // For XOR(^) operator
        // T^T = F, T^F = T, F^T = T, F^F = F
        else {
            if(isTrue) {
                ways = (ways + (lF * rT)%mod + (lT * rF)%mod)%mod;
            }
            else {
                ways = (ways + (lT * rT)%mod + (lF * rF)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int main()
{
    string exp = "T&T&F^T";
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    cout<<"Answer : "<<f(0, n-1, 1, exp, dp);
    return 0;
}