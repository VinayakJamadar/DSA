// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 3 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(k+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n*(k+1))
// Reason : Using of vector of vector data structure of n*target size

// Total Space Complexity : O(n*(k+1))
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n*(k+1)) (i.e O(n*k) = O(1)+O(n*(k+1)))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 2, 2, 3};
    int n = arr.size(), k = 3;
    vector<vector<int>> dp(n, vector<int> (k+1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        for (int target = 0; target < k+1; target++)
        {
            // Base Case
            if(target == 0) dp[ind][0] = 1;
            // Base Case
            else if(ind == 0) {
                if(arr[0] == target) dp[ind][arr[0]] = 1;
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