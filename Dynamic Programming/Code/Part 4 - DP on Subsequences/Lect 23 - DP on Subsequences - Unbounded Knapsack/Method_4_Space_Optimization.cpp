// Topic : DP on Subsequences
// Problem : 0/1 Knapsack

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*max(n, maxW/minElementOf(wt)))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(maxW+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(maxW+1)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(maxW+1) (i.e O(1) = O(1)+O(maxW+1))

#include <bits/stdc++.h>
using namespace std;

// Space Optimization using Single Array/Row

int main()
{
    vector<int> wt{2, 4, 6}, val{5, 11, 13};
    int n = wt.size(), maxW = 10;
    vector<int> previous(maxW+1, -1);

    for (int ind = 0; ind < n; ind++)
    {
        for (int w = 0; w < maxW+1; w++)
        {
            // Base Case
            if(ind == 0) {
                if(wt[ind] <= w) {
                    previous[w] = (w/wt[ind])*val[ind];
                }
                else previous[w] = INT_MIN;
            }
            else {
                // Recursive Case
                int notPick = 0 + previous[w];
                int pick = INT_MIN;
                if(wt[ind] <= w) {
                    pick = val[ind] + previous[w-wt[ind]];
                }
                previous[w] = max(pick, notPick);
            }
        }
    }
    
    cout<<"Answer : "<<previous[maxW];
    return 0;
}


// Space Optimization using Two Arrays/Rows

// int main()
// {
//     vector<int> wt{2, 4, 6}, val{5, 11, 13};
//     int n = wt.size(), maxW = 10;
//     vector<int> previous(maxW+1, -1);

//     for (int ind = 0; ind < n; ind++)
//     {
//         vector<int> current(maxW+1, -1);
//         for (int w = 0; w < maxW+1; w++)
//         {
//             // Base Case
//             if(ind == 0) {
//                 if(wt[ind] <= w) {
//                     current[w] = val[ind];
//                 }
//                 else current[w] = 0;
//             }
//             else {
//                 // Recursive Case
//                 int notPick = 0 + previous[w];
//                 int pick = INT_MIN;
//                 if(wt[ind] <= w) {
//                     pick = val[ind] + current[w-wt[ind]];
//                 }
//                 current[w] = max(pick, notPick);
//             }
//         }
//         previous = current;
//     }
    
//     cout<<"Answer : "<<previous[maxW];
//     return 0;
// }