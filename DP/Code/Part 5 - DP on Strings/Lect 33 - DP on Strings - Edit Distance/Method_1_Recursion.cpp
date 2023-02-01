// Topic : DP on Strings
// Problem : Edit Distance


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(3^(n+m))
// Reason : As we are calling 3 recursive calls for n+m times


// Auxilliary Space Complexity : O(n+m)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n+m)
// Reason : Sum of Auxilliary Space Complexity O(n+m) and Non-Auxilliary Space Complexity O(1) (i.e O(n+m) = O(n+m) + O(1))


// Answer : 5

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s, string t) {
    // Base Case
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    // Recursive Case
    if(s[i] == t[j]) return 0 + f(i-1, j-1, s, t);
    else {
        // 1. Insert
        int insert = f(i, j-1, s, t);
        // 2. Remove
        int remove = f(i-1, j, s, t);
        // 3. Replace
        int replace = f(i-1, j-1, s, t);

        return 1 + min(insert, min(remove, replace));
    }
}

int main()
{
    string s = "intention", t = "execution";
    int n = s.size(), m = t.size();
    
    cout<<"Answer : "<<f(n-1, m-1, s, t);
    return 0;
}