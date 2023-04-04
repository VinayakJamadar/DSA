// Topic : 2D DP
// Problem : Ninja's Training

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * 4 * 3)
// Reason : As we are using three nested For Loops. With n, 4, and 3 iterations.

// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n * 4)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n * 4)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(n) = O(1)+O(n * 4))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> points = {  
                                    {10, 40, 70},
                                    {20, 50, 80},
                                    {30, 60, 90}
                                };
    int n = points.size();
    
    vector<vector<int>> dp(n, vector<int> (4, -1));

    // Base Case
    for (int last = 0; last < 4; last++)
    {
        int maxPoint = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int point = points[0][task];
                maxPoint = max(maxPoint, point);
            }
        }
        dp[0][last] = maxPoint;
    }
    
    // Recursive Case
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxPoint = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    maxPoint = max(maxPoint, point);
                }
            }
            dp[day][last] = maxPoint;
        }
    }

    cout<<"Maximum Points : "<<dp[n-1][3];
    return 0;
}