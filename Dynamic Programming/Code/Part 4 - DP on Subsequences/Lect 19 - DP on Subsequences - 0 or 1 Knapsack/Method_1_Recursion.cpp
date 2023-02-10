// Topic : DP on Subsequences
// Problem : 0/1 Knapsack

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int>& wt, vector<int>& val) {
    // Base Case
    if(ind == 0){
        if(wt[ind] <= w) {
            return val[ind];
        }
        else return 0;
    }

    // Recursive Case
    int notPick = 0 + f(ind-1, w, wt, val);
    int pick = 0;
    if(wt[ind] <= w) {
        pick = val[ind] + f(ind-1, w-wt[ind], wt, val);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> wt{1, 2, 4, 5}, val{5, 4, 8, 6};
    int n = wt.size(), maxW = 5;
    
    cout<<"Answer : "<<f(n-1, maxW, wt, val);
    return 0;
}