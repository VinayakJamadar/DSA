// Topic : DP on Strings
// Problem : Longest Palindromic Subsequence


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^(2n))
// Reason : As we are calling 2 recursive calls for 2*n times


// Auxiliary Space Complexity : O(2n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(2n)
// Reason : Sum of Auxiliary Space Complexity O(2*n) and Non-Auxiliary Space Complexity O(1) (i.e O(2n) = O(2n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t) {
    // Base Case
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    if(s[i] == t[j]) return 1 + f(i-1, j-1, s, t);
    return max(f(i-1, j, s, t), f(i, j-1, s, t));
}

int main()
{
    string s = "bbbab", t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    
    cout<<"Answer : "<<f(n-1, n-1, s, t);
    return 0;
}