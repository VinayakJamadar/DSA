// Topic : DP on Subsequences
// Problem : Rod Cutting Problem


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(n+1))
// Reason : As we are using two nested For Loops (n and n+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(n+1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n+1) (i.e O(1) = O(1)+O(n+1))

#include <bits/stdc++.h>
using namespace std;

// Space Optimization using Single Array/Row

int main()
{
    vector<int> arr{2, 5, 7, 8, 10};
    int n = arr.size();
    vector<int> previous(n+1, -1);
    
    for (int ind = 0; ind < n; ind++)
    {
        for (int len = 0; len < n+1; len++)
        {
            // Base Case
            if(ind == 0) previous[len] = len*arr[ind];
            // Recursive Case
            else {
                int notPick = 0 + previous[len];
                int pick = INT_MIN;
                if(ind+1 <= len) {
                    pick = arr[ind] + previous[len-(ind+1)];
                }
                previous[len] = max(pick, notPick);
            }
        }
    }

    cout<<"Answer : "<<previous[n];
    return 0;
}

// Space Optimization using Two Arrays/Rows

// int main()
// {
//     vector<int> arr{2, 5, 7, 8, 10};
//     int n = arr.size();
//     vector<int> previous(n+1, -1);
    
//     for (int ind = 0; ind < n; ind++)
//     {
//         vector<int> previous(n+1, -1);
//         for (int len = 0; len < n+1; len++)
//         {
//             // Base Case
//             if(ind == 0) previous[len] = len*arr[ind];
//             // Recursive Case
//             else {
//                 int notPick = 0 + previous[len];
//                 int pick = INT_MIN;
//                 if(ind+1 <= len) {
//                     pick = arr[ind] + previous[len-(ind+1)];
//                 }
//                 previous[len] = max(pick, notPick);
//             }
//         }
//         previous = previous;
//     }

//     cout<<"Answer : "<<previous[n];
//     return 0;
// }