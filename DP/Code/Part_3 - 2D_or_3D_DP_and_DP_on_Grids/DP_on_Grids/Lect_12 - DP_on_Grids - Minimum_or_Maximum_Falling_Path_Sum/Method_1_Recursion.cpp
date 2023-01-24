// Topic : DP on Grids
// Problem : Maximum Path Sum in the matrix

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(m * 3^n)
// Reason O(m) : As we are using For Loop of m size
// Reason O(3^n) : As we are calling 3 recursive calls { i.e up = f(i-1, j), leftDiagonal = f(i-1, j-1, matrix) and rightDiagonal = f(i-1, j+1, matrix) } for n (no. of rows) times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, 0))

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& matrix) {
    // Base Case
    if(j < 0 or j >= matrix[0].size()) return INT_MIN;
    if(i == 0) return matrix[i][j];

    // Recursive Case
    int up = f(i-1, j, matrix);
    int leftDiagonal = f(i-1, j-1, matrix);
    int rightDiagonal = f(i-1, j+1, matrix);
    return matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };
    int n = matrix.size(), m = matrix[0].size();

    int ans = INT_MIN;
    for (int k = 0; k < m; k++)
    {
        ans = max(ans, f(n-1, k, matrix));
    }
    cout<<"Maximum Path Sum in the matrix : "<<ans;
    return 0;
}