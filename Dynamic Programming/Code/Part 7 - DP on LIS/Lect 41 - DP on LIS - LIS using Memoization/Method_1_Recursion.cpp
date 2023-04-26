// Topic : DP on LIS
// Problem : Length of Longest Increasing Subsequence

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int prev_ind, vector<int>& arr) {
    // Base Case
    if(ind == arr.size()) return 0;
    // Recursive Case
    int notPick = 0 + f(ind+1, prev_ind, arr);
    int pick = 0;
    if(prev_ind == -1 or (prev_ind != -1 and arr[ind] > arr[prev_ind])) pick = 1 + f(ind+1, ind, arr);
    return max(notPick, pick);
}

int main()
{
    vector<int> arr{10, 9, 2, 5, 3, 7, 101, 18};
    
    cout<<"Answer : "<<f(0, -1, arr);
    return 0;
}