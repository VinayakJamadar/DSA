// Topic : DP on triangles
// Problem : Minimum path sum in Triangular Grid

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops.


// Auxiliary Space Complexity : O(1)
// Reason : No Auxiliary Space

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n) (i.e O(1) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    int n = triangle.size();
    vector<int> front(n, -1);
    for (int i = n-1; i >= 0; i--)
    {
        vector<int> cur(n, -1);
        for (int j = i; j >= 0; j--)
        {
            // Base Case
            if(i == n-1) cur[j] = triangle[i][j];
            // Recursive Case
            else {
                int down = front[j];
                int diagonal = front[j+1];
                cur[j] = triangle[i][j] + min(down, diagonal);
            }
        }
        front = cur;
    }
    
    cout<<"Minimum path sum in Triangular Grid : "<<front[0];
    return 0;
}