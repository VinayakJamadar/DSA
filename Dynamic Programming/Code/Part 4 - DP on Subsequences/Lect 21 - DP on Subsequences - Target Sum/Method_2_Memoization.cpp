// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n*(k+1))
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only n*(k+1) values (i.e calculating and storing the values in dp[ind][target]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[ind][target])


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(k+1))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(n) + O(n*(k+1))
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(n*(k+1))


// Output :
// Answer : 2

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE :
// This Problem is similar to Lect_18 of DP Playlist, they just changed the wording of Problem Statement to confuse us.


// Approach :
// As given in problem we have to partition set into two subset s1 (sum of subset1) and s2 (sum of subset2), where s1 > s2
// Consider 
// s1 - s2 = d  ...... eqn 1 
// s1 + s2 = totalSum ...... eqn 2
// eqn 2 can be written as
// then s1 = totalSum - s2 ...... eqn 3
// put eqn 3 in eqn 1
// totalSum - s2 - s2 = d
// totalSum - 2*s2 = d
// i.e s2 = (totalSum - d)/2 ..... eqn 4

// Two Edge Cases of eqn 4
// 1. totalSum - d is negative (i.e totalSum - d < 0) --> Reason : not possible
// 2. totalSum - d is odd --> Reason : If totalSum - d is odd then (totalSum-d)/2 which gives decimal value and As array elements are integer so value can't be a decimal

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
    vector<int> arr{1, 2, 3, 1};
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0), d = 3;

    int answer;
    if((totalSum-d < 0) or (totalSum-d)%2) answer = 0;
    else {
        int k = (totalSum - d)/2;
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        answer = f(n-1, k, arr, dp);
    }
    cout<<"Answer : "<<answer;
    return 0;
}