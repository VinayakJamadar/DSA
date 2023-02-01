// Topic : 3D DP
// Problem : Ninja and his friends

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(9^n)
// Reason : As we are calling 9 recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int n, int m, vector<vector<int>>& matrix) {
    // Base Case
    if((j1 < 0 or j1 >= m) or (j2 < 0 or j2 >= m)) return INT_MIN;
    if(i == n-1) {
        if(j1 == j2) return matrix[i][j1];
        else return matrix[i][j1] + matrix[i][j2];
    }
    
    // Recursive Case
    int maxi = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if((j1+dj1) == (j2+dj2)) value = matrix[i][j1] + f(i+1, j1+dj1, j2+dj2, n, m, matrix);
            else value = matrix[i][j1] + matrix[i][j2] + f(i+1, j1+dj1, j2+dj2, n, m, matrix);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int main()
{
    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = matrix.size(), m = matrix[0].size();
    cout<<"Answer : "<<f(0, 0, m-1, n, m, matrix);
    return 0;
}