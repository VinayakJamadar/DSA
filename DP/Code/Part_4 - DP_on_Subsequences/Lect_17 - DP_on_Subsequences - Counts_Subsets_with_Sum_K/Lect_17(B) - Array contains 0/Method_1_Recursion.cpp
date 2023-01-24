// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))


// Output :
// Answer : 4

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int>& arr) {
    // Base Case
    if(ind == 0) {
        if(target == 0 and arr[0] == 0) return 2;
        else if(target == 0 or arr[0] == target) return 1;
        else return 0;
    }

    // Recursive Case
    int notPick = f(ind-1, target, arr);
    int pick = 0;
    if(target >= arr[ind]) {
        pick = f(ind-1, target-arr[ind], arr);
    }
    return notPick + pick;
}

int main()
{
    vector<int> arr{0, 0, 1};
    int n = arr.size(), k = 1;
    
    cout<<"Answer : "<<f(n-1, k, arr);
    return 0;
}