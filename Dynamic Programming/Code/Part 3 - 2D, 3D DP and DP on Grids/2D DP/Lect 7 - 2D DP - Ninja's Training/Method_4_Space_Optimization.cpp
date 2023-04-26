// Topic : 2D DP
// Problem : Ninja's Training

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * 4 * 3)
// Reason : As we are using three nested For Loops. With n, 4, and 3 iterations.


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(4)
// Reason : Using of vector data structure of 4 size

// Total Space Complexity : O(4)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(1) (i.e O(1) = O(1)+O(4))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> points = {  
                                    {10, 40, 70},
                                    {20, 50, 80},
                                    {30, 60, 90}
                                };
    int n = points.size();
    
    vector<int> prev(4, -1);

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
        prev[last] = maxPoint;
    }
    
    // Recursive Case
    for (int day = 1; day < n; day++)
    {
        vector<int> cur(4, -1);
        for (int last = 0; last < 4; last++)
        {
            int maxPoint = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    maxPoint = max(maxPoint, point);
                }
            }
            cur[last] = maxPoint;
        }
        prev = cur;
    }

    cout<<"Maximum Points : "<<prev[3];
    return 0;
}