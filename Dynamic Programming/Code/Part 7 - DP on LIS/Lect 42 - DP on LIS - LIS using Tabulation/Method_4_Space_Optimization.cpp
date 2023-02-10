// Topic : DP on LIS
// Problem : Length of Longest Increasing Subsequence

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(n+1))
// Reason : As we are using two nested For Loops (n and n+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n+1)
// Reason : Using vector data structure of n+1 size

// Total Space Complexity : O(n+1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n+1) (i.e O(1) = O(1)+O(n+1))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    vector<int> cur(n+1, 0), next(n+1, 0);

    for(int ind = n-1; ind >= 0; ind--) {
        for(int prev_ind = ind; prev_ind >= 0; prev_ind--) {
            int notPick = 0 + next[prev_ind];
            int pick = 0;
            if(prev_ind == 0 or (prev_ind != 0 and arr[ind] > arr[prev_ind-1])) pick = 1 + next[ind+1];
            cur[prev_ind] = max(notPick, pick);
        }
        next = cur;
    }
    
    cout<<"Answer : "<<next[0];

    return 0;
}