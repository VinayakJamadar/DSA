// Topic : 1D DP
// Problem : Frog Jump with K Jumps

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O(n * k)
// Reason :
// O(n) : As we avoided the overlapping subproblem. So mostly we have to calculate only n values (i.e calculating and storing the values in dp[n]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[n])
// O(k) : As we are using a for loop of k iterations.


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : using of vector data structure

// Total Space Complexity : O(n) + O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int k, vector<int>& height, vector<int>& dp) {
    if(ind <= 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int minJump = INT_MAX;
    for(int i = 1; i <= k; i++) {
        int ithJump = INT_MAX;
        if(ind-i >= 0) {
            ithJump = f(ind-i, k, height, dp) + abs(height[ind] - height[ind-i]);
        }
        minJump = min(minJump, ithJump);
    }
    return dp[ind] = minJump;
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size(), k = 2;
    vector<int> dp(n, -1);
    cout<<"MinEnergy("<<n<<") : "<<f(n-1, k, height, dp);
    return 0;
}