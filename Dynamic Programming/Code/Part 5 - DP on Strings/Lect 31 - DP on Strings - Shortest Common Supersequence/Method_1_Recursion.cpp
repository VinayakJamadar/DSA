// Topic : DP on Strings
// Problem : Shortest Common Supersequence


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^(n+m))
// Reason : As we are calling 2 recursive calls for n+m times


// Auxiliary Space Complexity : O(n+m)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n+m)
// Reason : Sum of Auxiliary Space Complexity O(n+m) and Non-Auxiliary Space Complexity O(1) (i.e O(n+m) = O(n+m) + O(1))

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, string s, string t, string& lcs) {
//     // Base Case
//     if(i < 0 or j < 0) return 0;

//     // Recursive Case
//     if(s[i] == t[j]) {
//         lcs += s[i];
//         return 1 + f(i-1, j-1, s, t, lcs);
//     }
//     return max(f(i-1, j, s, t, lcs), f(i, j-1, s, t, lcs));
// }

// int main()
// {
//     string s = "acd", t = "ced", lcs = "";
//     int n = s.size(), m = t.size();
    
//     int len = f(n-1, m-1, s, t, lcs);
//     reverse(lcs.begin(), lcs.end());
//     cout<<"Lcs is : "<<lcs<<" and length of lcs is : "<<len;
//     return 0;
// }