// Topic : 1D DP
// Problem : Frog Jump

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n)
// Reason : As we are using a For Loop of n iterations


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n) (i.e O(n) = O(1)+O(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int ind = 1; ind < n; ind++) {
        int jumpOne = dp[ind-1] + abs(height[ind] - height[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
        dp[ind] = min(jumpOne, jumpTwo);
    }

    cout<<"MinEnergy("<<n<<") : "<<dp[n-1];
    return 0;
}