// Topic : 2D DP
// Problem : Ninja's Training

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(3 ^ (n * 4))
// Reason :
// O(n * 4) : As each day their can be 4 possible last (0 to 3) value. Therefore n*4 states are possible
// O(3^(n * 4)): As we are calling 3 recursive calls everytime for calculating n * 4 states

// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n)+O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> points) {
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

    // Recursive Case
    int maxPoint = 0;
    for (int task = 0; task < 3; task++)
    {
        if(task != last) {
            int point = points[day][task] + f(day-1, task, points);
            maxPoint = max(maxPoint, point);
        }
    }
    return maxPoint;
}

int main()
{
    vector<vector<int>> points = {  
                                    {10, 40, 70},
                                    {20, 50, 80},
                                    {30, 60, 90}
                                };
    int n = points.size();
    cout<<"Maximum Points : "<<f(n-1, 3, points);
    return 0;
}