// Topic : DP on Strings
// Problem : Longest Common Subsequence


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : Exponential

// Auxiliary Space Complexity : O(n+m)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n+m)
// Reason : Sum of Auxiliary Space Complexity O(n+m) and Non-Auxiliary Space Complexity O(1) (i.e O(n+m) = O(n+m) + O(1))

#include <bits/stdc++.h>
using namespace std;

bool f(int i, int j, string pattern, string text) {
    // Base Case
    if(i < 0 and j < 0) return true;
    if(i < 0 and j >= 0) return false;
    if(j < 0 and i >= 0) {
        for (int k = i; k >= 0; k++)
        {
            if(pattern[k] != '*') return false;
        }
        return true;
    }

    // Recursive Case
    if(pattern[i] == text[j] or pattern[i] == '?') return f(i-1, j-1, pattern, text);
    else {
        if(pattern[i] == '*') {
            return f(i-1, j, pattern, text) or f(i, j-1, pattern, text);
        }
        else {
            return false;
        }
    }
}

int main()
{
    string pattern = "ba*a?", text = "baaabab";
    int n = pattern.size(), m = text.size();
    
    cout<<"Answer : "<<f(n-1, m-1, pattern, text);
    return 0;
}