// Topic : DP on Subsequences
// Problem : Partition A Set Into Two Subsets With Minimum Absolute Sum Difference

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(k+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(k+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(k+1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(k+1) (i.e O(1) = O(1)+O(k+1))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE ON Tabulation : 
// If we carefully observe by displaying the dp matrix (i.e dp[n-1][k]) that is generated by Tabulation in DP Lect 14.
// The last row i.e dp[n-1][0 ... k] and In Space Optimization last row is previous vector 
// So, previous vector will represent whether the any subsequence or subset has a sum from 0 to k.

// Step 1 : So using this NOTE we can take sum of all elements of array as totalSum
// Step 2 : Generate a previous[(k/2)+1] matrix, where k = totalSum/2 using tabulation.
// Step 3 : Then traverse last row i.e dp[n-1] in reverse direction and search for true value (i.e dp[n-1][ind] == 1)
// Step 4 : So sum1 = ind and sum2 = totalSum - ind are the partition sum of two subset subset1 and subset 2 of a Set.
// Step 5 : Then Answer i.e Minimum Absolute Sum Difference of subset1 and subset2 is ans = abs(sum1 - sum2);

int main()
{
    vector<int> arr{3, 2, 7};
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0);

    int k = totalSum/2;
    vector<bool> previous(k+1, 0);
    for (int ind = 0; ind < n; ind++)
    {
        vector<bool> current(k+1, 0);
        for (int target = 0; target < k+1; target++)
        {
            // Base Case
            if(target == 0) current[0] = 1;
            // Base Case
            else if(ind == 0) {
                if(arr[0] == target) current[arr[0]] = 1;
            }
            // Recursive Case
            else {
                bool notPick = previous[target];
                bool pick = 0;
                if(target >= arr[ind]) {
                    pick = previous[target-arr[ind]];
                }
                current[target] = notPick or pick;
            }
        }
        previous = current;
    }

    int ans;
    for (int ind = k; ind >= 0; ind--)
    {
        if(previous[ind]) {
            int sum1 = ind, sum2 = totalSum - ind;
            ans = abs(sum1-sum2);
            break;
        }
    }
    cout<<"Answer : "<<ans<<endl;
    return 0;
}