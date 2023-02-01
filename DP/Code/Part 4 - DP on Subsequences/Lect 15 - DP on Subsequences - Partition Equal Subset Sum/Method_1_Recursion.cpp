// Topic : DP on Subsequences
// Problem : Partition Equal Subset Sum

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

bool f(int ind, int target, vector<int>& arr) {
    // Base Case
    if(target == 0) return 1;
    if(ind == 0) {
        if(arr[0] == target) return 1;
        else return 0;
    }

    // Recursive Case
    bool notPick = f(ind-1, target, arr);
    bool pick = 0;
    if(target >= arr[ind]) {
        pick = f(ind-1, target-arr[ind], arr);
    }
    return notPick or pick;
}

int main()
{
    vector<int> arr{2, 3, 3, 3, 4, 5};
    int n = arr.size(), k = accumulate(arr.begin(), arr.end(), 0);
    // If k (i.e sum of array elements is odd then Answer is always false)
    if(k&1) cout<<"Answer : false"<<endl;
    // Else find a subset with sum equal to k/2
    else {
        // If we get true then definitely there is another subset whose sum is equal to k/2. So, we can partition array into two subset both having same sum. And Answer is true
        // Else Answer is false
        k = k/2;
        cout<<"Answer : "<<(f(n-1, k, arr) ? "true" : "false");
    }
    return 0;
}