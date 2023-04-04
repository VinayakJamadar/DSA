// Topic : DP on Grids
// Problem : Unique Paths

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2 ^ max(m , n))
// Reason : As we are calling 2 recursive calls { i.e up = f(i-1, j) and left = f(i, j-1) } for m * n times

// Auxilliary Space Complexity : O(m + n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(m + n)
// Reason : Sum of Auxilliary Space Complexity O(m + n) and Non-Auxilliary Space Complexity O(1) (i.e O(m + n) = O(m + n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j) {
    // Base Case
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0) return 0;

    // Recursive Case
    int up = f(i-1, j);
    int left = f(i, j-1);
    return up+left;
}

int main()
{
    int m = 3, n = 7;
    cout<<"Unique Paths : "<<f(m-1, n-1);
    return 0;
}