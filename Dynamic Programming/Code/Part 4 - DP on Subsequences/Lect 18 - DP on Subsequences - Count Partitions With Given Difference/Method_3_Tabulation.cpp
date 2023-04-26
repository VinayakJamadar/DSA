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
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n*(k+1)) (i.e O(n*(k+1)) = O(1)+O(n*(k+1)))


// Output :
// Answer : 1

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> arr{5, 2, 6, 4};
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0), d = 3;

    int answer;
    if((totalSum-d < 0) or (totalSum-d)%2) answer = 0;
    else {
        int k = (totalSum - d)/2;
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
        answer = dp[n-1][k];
    }
    cout<<"Answer : "<<answer;
    return 0;
}