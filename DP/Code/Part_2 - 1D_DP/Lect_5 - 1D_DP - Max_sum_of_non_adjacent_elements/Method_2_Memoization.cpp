// Topic : 1D DP
// Problem : Maximum sum of non-adjacent elements

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n)
// Reason : As we avoided the overlapping subproblem. So mostly we have to calculate only n values (i.e calculating and storing the values in dp[n]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[n])


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : using of vector data structure

// Total Space Complexity : O(n) + O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int>& arr, vector<int>& dp) {
    if(ind == 0) return arr[0];
    if(ind < 0) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    int pick = arr[ind] + f(ind-2, arr, dp);
    int notPick = 0 + f(ind-1, arr, dp);
    return dp[ind] = max(pick, notPick);
}

int main(){
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    
    cout<<"Max Sum of non-adjacent elements : "<<f(n-1, arr, dp);
    return 0;
}