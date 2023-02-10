// Topic : DP on Grids
// Problem : Unique Paths with Obstacles

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2 ^ max(n , m))
// Reason : As we are calling 2 recursive calls { i.e up = f(i-1, j) and left = f(i, j-1) } for n * m times

// Auxilliary Space Complexity : O(n + m)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n + m)
// Reason : Sum of Auxilliary Space Complexity O(n + m) and Non-Auxilliary Space Complexity O(1) (i.e O(n + m) = O(n + m) + O(1))

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int f(int i, int j, vector<vector<int>>& maze) {
    // Base Case
    if(i == 0 and j == 0) return 1;
    if((i < 0 or j < 0) or maze[i][j] == -1) return 0;

    // Recursive Case
    int up = f(i-1, j, maze);
    int left = f(i, j-1, maze);
    return (up+left)%mod;
}

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    int n = maze.size(), m = maze[0].size();
    cout<<"Unique Paths with Obstacles : "<<f(n-1, m-1, maze);
    return 0;
}