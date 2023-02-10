// Topic : 1D DP
// Problem : Frog Jump with K Jumps

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * k)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with k iterations.


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using of vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(n) = O(1)+O(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size(), k = 2;
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int ind = 1; ind < n; ind++) {
        int minJump = INT_MAX;
        for(int i = 1; i <= k; i++) {
            int ithJump = INT_MAX;
            if(ind-i >= 0) {
                ithJump = dp[ind-i] + abs(height[ind] - height[ind-i]);
            }
            minJump = min(minJump, ithJump);
        }
        dp[ind] = minJump;
    }

    cout<<"MinEnergy("<<n<<") : "<<dp[n-1];
    return 0;
}