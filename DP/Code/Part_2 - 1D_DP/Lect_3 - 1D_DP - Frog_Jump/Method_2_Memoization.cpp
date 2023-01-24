// Topic : 1D DP
// Problem : Frog Jump

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

int f(int ind, vector<int>& height, vector<int>& dp) {
    if(ind <= 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int jumpOne = f(ind-1, height, dp) + abs(height[ind] - height[ind-1]);
    int jumpTwo = INT_MAX;
    if(ind > 1)
        jumpTwo = f(ind-2, height, dp) + abs(height[ind]-height[ind-2]);
    return dp[ind] = min(jumpOne, jumpTwo);
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout<<"MinEnergy("<<n<<") : "<<f(n-1, height, dp);
    return 0;
}