// Topic : DP on Subsequences
// Problem : 0/1 Knapsack

// Method 1 : Using Recursion (Top-Don Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^max(n, maxW/minElementOf(wt)))
// Reason : As we are calling 2 recursive calls for max(n, maxW/minElementOf(wt)) times


// Auxiliary Space Complexity : O(max(n, maxW/minElementOf(wt)))
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of ros)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(max(n, maxW/minElementOf(wt)))
// Reason : Sum of Auxiliary Space Complexity O(max(n, maxW/minElementOf(wt))) and Non-Auxiliary Space Complexity O(1) (i.e O(max(n, maxW/minElementOf(wt))) = O(max(n, maxW/minElementOf(wt))) + O(1))

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int>& wt, vector<int>& val) {
    // Base Case
    if(ind == 0){
        if(w%wt[ind] == 0) return (w/wt[ind])*val[ind];
        else return INT_MIN;
    }

    // Recursive Case
    int notPick = 0 + f(ind-1, w, wt, val);
    int pick = INT_MIN;
    if(w >= wt[ind]) {
        pick = val[ind] + f(ind, w-wt[ind], wt, val);
    }
    return max(notPick, pick);
}

int main(){
    vector<int> wt{2, 4, 6}, val{5, 11, 13};
    int n = wt.size(), maxW = 10;

    cout<<"Answer : "<<f(n-1, maxW, wt, val);
    return 0;
}