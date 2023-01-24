// Topic : DP on Grids
// Problem : Minimum Path Sum in Grid

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * m)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with m iterations.


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(m)
// Reason : Using of vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(m) (i.e O(1) = O(1)+O(m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, -1);
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(i == 0 and j == 0) cur[0] = grid[0][0];
            // Recursive Case
            else {
                int up = INT_MAX, left = INT_MAX;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j-1];
                cur[j] = grid[i][j] + min(up, left);
            }
        }
        prev = cur;
    }
    cout<<"Minimum Path Sum in Grid : "<<prev[m-1]<<endl;
    return 0;
}