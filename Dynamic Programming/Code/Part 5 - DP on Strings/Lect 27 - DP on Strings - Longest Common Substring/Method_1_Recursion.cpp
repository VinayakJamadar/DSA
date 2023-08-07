// Topic : DP on Strings
// Problem : Longest Common Substring


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^(n+m))
// Reason : As we are calling 2 recursive calls for n+m times


// Auxiliary Space Complexity : O(n+m)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n+m)
// Reason : Sum of Auxiliary Space Complexity O(n+m) and Non-Auxiliary Space Complexity O(1) (i.e O(n+m) = O(n+m) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t, int& len) {
    // Base Case
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    int val;
    if(s[i] == t[j]) {
        val = 1 + f(i-1, j-1, s, t, len);
        len = max(len, val);
        return val;
    }
    else {
        val = max(f(i-1, j, s, t, len), f(i, j-1, s, t, len));
        len = max(len, val);
        return 0;
    }
}

int main()
{
    string s = "abcdef", t = "abzdefy";
    int n = s.size(), m = t.size(), len = 0;
    
    f(n-1, m-1, s, t, len);
    cout<<"Length of longest common substring is : "<<len;
    return 0;
}