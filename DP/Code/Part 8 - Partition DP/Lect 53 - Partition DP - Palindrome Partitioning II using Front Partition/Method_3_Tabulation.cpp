// Topic : Partition DP
// Problem : Palindrome Partitioning - II using Front Partitioning

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops (n and n iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using of vector of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(n) = O(1)+O(n))

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

int main()
{
    string str = "ABBAC";
    int n = str.size();
    vector<int> dp(n+1, -1);
    // Base Case
    dp[n] = 0;
    // Recursive Case
    for (int i = n-1; i >= 0; i--)
    {
        int minCuts = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if(isPalindrome(i, j, str)) {
                int cuts = 1 + dp[j+1];
                minCuts = min(minCuts, cuts);
            }
        }
        dp[i] = minCuts;
    }
    
    cout<<"Minimum Cuts : "<<dp[0]-1;
    return 0;
}