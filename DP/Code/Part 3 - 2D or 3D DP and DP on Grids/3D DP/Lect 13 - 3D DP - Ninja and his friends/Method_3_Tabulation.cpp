// Topic : 3D DP
// Problem : Ninja and his friends

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m*m*9)
// Reason : As we are using five nested For Loops. (n, m, m, 3, 3 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*m*m)
// Reason : Using of vector of vector data structure of n * m size

// Total Space Complexity : O(n*m*m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*m*m) (i.e O(n*m*m) = O(1)+O(n*m*m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

    for (int i = n-1; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if(i == n-1) {
                    if(j1 == j2) dp[i][j1][j2] = matrix[i][j1];
                    else dp[i][j1][j2] = matrix[i][j1] + matrix[i][j2];
                }
                else {
                    int maxi = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            if(!((j1+dj1 < 0 or j1+dj1 >= m) or (j2+dj2 < 0 or j2+dj2 >= m))) {
                                int value = 0;
                                if((j1+dj1) == (j2+dj2)) value = matrix[i][j1] + dp[i+1][j1+dj1][j2+dj2];
                                else value = matrix[i][j1] + matrix[i][j2] + dp[i+1][j1+dj1][j2+dj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
    }

    cout<<"Answer : "<<dp[0][0][m-1];
    return 0;
}