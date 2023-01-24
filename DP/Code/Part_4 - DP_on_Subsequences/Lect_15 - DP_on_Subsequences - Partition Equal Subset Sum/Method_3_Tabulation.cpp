// Topic : DP on Subsequences
// Problem : Partition Equal Subset Sum

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
    vector<int> arr{2, 3, 3, 3, 4, 5};
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0);
    
    // If totalSum (i.e sum of array elements) is odd then Answer is always false
    if(totalSum&1) cout<<"Answer : false"<<endl;
    // Else find a subset with sum equal to totalSum/2
    else {
        // If we get true then definitely there is another subset whose sum is equal to totalSum/2. So, we can partition array into two subset both having same sum. And Answer is true
        // Else Answer is false
        int k = totalSum/2;
        vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
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
                    bool notPick = dp[ind-1][target];
                    bool pick = 0;
                    if(target >= arr[ind]) {
                        pick = dp[ind-1][target-arr[ind]];
                    }
                    dp[ind][target] = notPick or pick;
                }
            }
        }
        for (int i = 0; i < k+1; i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k+1; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"Answer : "<<(dp[n-1][k] ? "true" : "false");
    }
    return 0;
}