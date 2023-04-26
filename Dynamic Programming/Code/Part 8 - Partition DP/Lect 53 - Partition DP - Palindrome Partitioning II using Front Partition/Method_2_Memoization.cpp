// Topic : Partition DP
// Problem : Palindrome Partitioning - II using Front Partitioning

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*n)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only values (i.e calculating and storing the values in dp[i]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using of vector data structure

// Total Space Complexity : O(n) + O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string& str)
{
    while(i < j) {
        if(str[i] != str[j]) return 0;
        i++, j--;
    }
    return 1;
}

int f(int i, int n, string& str, vector<int>& dp) {
    // Base Case
    if(i == n) return 0;
    // Recursive Case
    if(dp[i] != -1) return dp[i];
    int minCuts = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if(isPalindrome(i, j, str)) {
            int cuts = 1 + f(j+1, n, str, dp);
            minCuts = min(minCuts, cuts);
        }
    }
    return dp[i] = minCuts;
}

int main()
{
    string str = "ABBAC";
    int n = str.size();
    vector<int> dp(n+1, -1);
    cout<<"Minimum Cuts : "<<f(0, n, str, dp)-1;
    return 0;
}