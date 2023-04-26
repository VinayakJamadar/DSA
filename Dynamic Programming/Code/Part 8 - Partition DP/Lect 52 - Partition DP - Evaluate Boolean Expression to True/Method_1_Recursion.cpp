// Topic : Partition DP
// Problem : Ways to Evaluate Boolean Expression to True

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(n^n*2)
// Reason : As we are calling n recursive calls for n*2 times


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll f(int i, int j, bool isTrue, string& exp) {
    // Base Case
    if(i == j) {
        if(isTrue) return (exp[i] == 'T');
        else return (exp[i] == 'F');
    }
    // Recursive Case
    ll ways = 0;
    for (int k = i+1; k <= j-1; k+=2)
    {
        ll lT = f(i, k-1, 1, exp); // leftTrue
        ll lF = f(i, k-1, 0, exp); // leftFalse
        ll rT = f(k+1, j, 1, exp); // rightTrue
        ll rF = f(k+1, j, 0, exp); // rightFalse
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
    return ways;
}

int main()
{
    string exp = "T&T&F^T";
    int n = exp.size();
    cout<<"Answer : "<<f(0, n-1, 1, exp);
    return 0;
}