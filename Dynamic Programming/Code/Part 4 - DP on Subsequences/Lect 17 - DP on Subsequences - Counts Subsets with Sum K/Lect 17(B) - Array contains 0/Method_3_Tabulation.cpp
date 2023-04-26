// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(k+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n*(k+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(k+1))
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(k+1)) (i.e O(n*k) = O(1)+O(n*(k+1)))


// Output :
// Answer : 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{0, 0, 1};
    int n = arr.size(), k = 1;
    vector<vector<int>> dp(n, vector<int> (k+1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target < k+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target == 0 and arr[0] == 0) dp[ind][target] = 2;
                else if(target == 0 or arr[0] == target) dp[ind][target] = 1;
                else dp[ind][target] = 0;
            }
            // Recursive Case
            else {
                int notPick = dp[ind-1][target];
                int pick = 0;
                if(target >= arr[ind]) {
                    pick = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = notPick + pick;
            }
        }
    }
    
    cout<<"Answer : "<<dp[n-1][k]<<endl;
    return 0;
}