// Topic : 1D DP
// Problem : Maximum sum of non-adjacent elements

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
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[0] = arr[0];

    for (int ind = 1; ind < n; ind++)
    {
        int pick = arr[ind];
        if(ind > 1) pick += dp[ind-2];
        
        int notPick = 0 + dp[ind-1];
        dp[ind] = max(pick, notPick);
    }
    
    cout<<"Max Sum of non-adjacent elements : "<<dp[n-1];
    return 0;
}