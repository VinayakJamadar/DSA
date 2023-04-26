// Topic : Partition DP
// Problem : Burst Balloons


// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n*2*n)
// Reason : As we are using three nested For Loops (n, n, 2 and n iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*n*2)
// Reason : Using of vector of vector data structure of n*n*2 size

// Total Space Complexity : O(n*n*2)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*n*2) (i.e O(n*n*2) = O(1)+O(n*n*2))

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int main()
{
    string exp = "T&T&F^T";
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                // Base Case
                if(i == j) {
                    if(isTrue) dp[i][j][isTrue] = (exp[i] == 'T');
                    else dp[i][j][isTrue] = (exp[i] == 'F');
                }
                // Recursive Case
                else {
                    ll ways = 0;
                    for (int k = i+1; k <= j-1; k+=2)
                    {
                        ll lT = dp[i][k-1][1]; // leftTrue
                        ll lF = dp[i][k-1][0]; // leftFalse
                        ll rT = dp[k+1][j][1]; // rightTrue
                        ll rF = dp[k+1][j][0]; // rightFalse
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
                    dp[i][j][isTrue] = ways;
                }
            }
        }
    }

    cout<<"Answer : "<<dp[0][n-1][1];
    return 0;
}