// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(k+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(k+1) values (i.e calculating and storing the values in dp[ind][target]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][target])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(k+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*(k+1))
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n*(k+1))


// Output :
// Answer : 4

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) {
        if(target == 0 and arr[0] == 0) return 2;
        else if(target == 0 or arr[0] == target) return 1;
        else return 0;
    }

    // Recursive Case
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = f(ind-1, target, arr, dp);
    int pick = 0;
    if(target >= arr[ind]) {
        pick = f(ind-1, target-arr[ind], arr, dp);
    }
    return dp[ind][target] = notPick + pick;
}

int main()
{
    vector<int> arr{0, 0, 1};
    int n = arr.size(), k = 1;
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    
    cout<<"Answer : "<<f(n-1, k, arr, dp)<<endl;
    return 0;
}