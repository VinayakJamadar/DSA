// Topic : DP on Grids
// Problem : Unique Paths

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(m * n)
// Reason : As we are using two nested For Loops. Outer For Loop with m iterations and Inner For Loop with n iterations.


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(1) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3, n = 7;
    vector<int> prev(n, -1);

    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, -1);
        for (int j = 0; j < n; j++)
        {
            // Base Case
            if(i == 0 and j == 0) cur[0] = 1;
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
    cout<<"Unique Paths : "<<prev[n-1]<<endl;
    return 0;
}