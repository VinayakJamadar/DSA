// Topic : 2D DP
// Problem : Ninja's Training

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n * 4 * 3)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n * 4 values (i.e calculating and storing the values in dp[day][last]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[day][last])
// And As we are using a For loop of 3 iterations final Complexity is O(n * 4 * 3)


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n * 4)
// Reason : using of vector data structure

// Total Space Complexity : O(n) + O(n * 4)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n * 4)

#include<bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    // Base Case
    if(day == 0) {
        int maxPoint = 0;
        for (int task = 0; task < 3; task++)
        {
            if(task != last) {
                int point = points[day][task];
                maxPoint = max(maxPoint, point);
            }
        }
        return maxPoint;
    }

    if(dp[day][last] != -1) return dp[day][last];

    // Recursive Case
    int maxPoint = 0;
    for (int task = 0; task < 3; task++)
    {
        if(task != last) {
            int point = points[day][task] + f(day-1, task, points, dp);
            maxPoint = max(maxPoint, point);
        }
    }
    return dp[day][last] = maxPoint;
}

int main(){
    vector<vector<int>> points = {  
                                    {10, 40, 70},
                                    {20, 50, 80},
                                    {30, 60, 90}
                                };
    int n = points.size();
    vector<vector<int>> dp(n, vector<int> (4, -1));
    cout<<"Maximum Points : "<<f(n-1, 3, points, dp);
    return 0;
}