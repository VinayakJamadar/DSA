// Topic : Partition DP
// Problem : Minimum cost to cut the stick

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O((c+2)*(c+2)*c)
// Reason : As we are using three nested For Loops (c+2, c+2 and c iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O((c+2)*(c+2))
// Reason : Using of vector of vector data structure of n*n size

// Total Space Complexity : O((c+2)*(c+2))
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O((c+2)*(c+2)) (i.e O((c+2)*(c+2)) = O(1)+O((c+2)*(c+2)))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE :

// 1. Reason for inserting 0 at front and n at back
// To get the length of currently cutting stick.

// 2. Reason for sorting 'cuts' array : 
// Now the problem that we face here is that the information that marking 1 can be cut is not passed into the correct CUTS array of the left subproblem rather it is lying in the CUTS array of the right subproblem. 
// Therefore these subproblems cannot be solved independently, thus defeating the whole point of a recursive solution. 
// In order to solve this problem, we can initially sort the CUTS array. 
// By sorting the CUTS array, we know that at whatever point we are making the cut, the information on the markings of the left portion will always be present on the left side of the CUTS array partition. Similarly on the right side.

// 3. After Sorting subproblems are independent of each other 
// i.e After Sorting subproblems dp[i][k-i] and dp[k+1][j] are independent of each other

int main()
{
    vector<int> cuts{1, 3, 4, 7};
    int n = 10, c = cuts.size();
    // Inserting 0 at front
    cuts.insert(cuts.begin(), 0);
    // Inserting n at back
    cuts.push_back(n);
    // Sort 'cuts'
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for (int i = c; i >= 1; i--)
    {
        // handled Base Case in loops
        for (int j = i; j <= c; j++)
        {
            // Recursive Case
            int mini = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int cost = (cuts[j+1]-cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    
    cout<<"Minimum cost to cut the stick is : "<<dp[1][c];
    return 0;
}