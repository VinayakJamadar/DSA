// Topic : DP on triangles
// Problem : Minimum path sum in Triangular Grid

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops.


// Auxiliary Space Complexity : O(1)
// Reason : No Auxiliary Space

// Non-Auxiliary Space Complexity : O(n*n)
// Reason : Using vector of vector data structure of n*n size

// Total Space Complexity : O(n*n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*n) (i.e O(n*n) = O(1)+O(n*n))

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
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            // Base Case
            if(i == n-1) dp[i][j] = triangle[i][j];
            // Recursive Case
            else {
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
    }
    
    cout<<"Minimum path sum in Triangular Grid : "<<dp[0][0];
    return 0;
}