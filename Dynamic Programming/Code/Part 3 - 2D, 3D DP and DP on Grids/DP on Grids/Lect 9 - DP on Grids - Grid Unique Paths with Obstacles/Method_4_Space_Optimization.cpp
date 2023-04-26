// Topic : DP on Grids
// Problem : Unique Paths with Obstacles

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * m)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with m iterations.


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(m)
// Reason : Using of vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(m) (i.e O(1) = O(1)+O(m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    int n = maze.size(), m = maze[0].size();
    vector<int> prev(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m, -1);
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(maze[i][j] == -1) cur[j] = 0;
            // Base Case
            else if(i == 0 and j == 0) cur[0] = 1;
            // Recursive Case
            else {
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j-1];
                cur[j] = up+left;
            }
        }
        prev = cur;
    }
    cout<<"Unique Paths with Obstacles : "<<prev[m-1]<<endl;
    return 0;
}