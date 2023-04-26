// Topic : DP on Subsequences
// Problem : Rod Cutting Problem


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^max(n, minElementOf(arr)))
// Reason : As we are calling 2 recursive calls for max(n, minElementOf(arr)) times


// Auxiliary Space Complexity : O(max(n, minElementOf(arr)))
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(max(n, minElementOf(arr)))
// Reason : Sum of Auxiliary Space Complexity O(max(n, minElementOf(arr))) and Non-Auxiliary Space Complexity O(1) (i.e O(max(n, minElementOf(arr))) = O(max(n, minElementOf(arr))) + O(1))


// Output :
// Answer : 12

#include <bits/stdc++.h>
using namespace std;

int f(int len, int n, vector<int>& arr) {
    // Base Case
    if(len == 0) return n*arr[len];

    // Recursive Case
    int notPick = 0 + f(len-1, n, arr);
    int pick = INT_MIN;
    if(len+1 <= n) {
        pick = arr[len] + f(len, n-(len+1), arr);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> arr{2, 5, 7, 8, 10};
    int n = arr.size();
    
    cout<<"Answer : "<<f(n-1, n, arr);
    return 0;
}