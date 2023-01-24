// Topic : DP on triangles
// Problem : Minimum path sum in Triangular Grid

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2 ^ ((n*(n+1))/2))
// Reason : As we are calling 2 recursive calls { i.e down = f(i+1, j) and diagonal = f(i+1, j+1) } for (n*(n+1))/2 times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == path length from (0, 0) to (n, 0))

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, int n, vector<vector<int>>& triangle) {
    // Base Case
    if(i == n-1) return triangle[i][j];

    // Recursive Case
    int down = f(i+1, j, n, triangle);
    int diagonal = f(i+1, j+1, n, triangle);
    return triangle[i][j] + min(down, diagonal);
}

int main()
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    int n = triangle.size();
    cout<<"Minimum path sum in Triangular Grid : "<<f(0, 0, n, triangle);
    return 0;
}