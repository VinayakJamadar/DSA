// Topic : DP on Subsequences
// Problem : Partition Equal Subset Sum

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(k+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(k+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(k+1)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(k+1) (i.e O(1) = O(1)+O(k+1))

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
        cout<<"Answer : "<<(previous[k] ? "true" : "false");
    }
    return 0;
}