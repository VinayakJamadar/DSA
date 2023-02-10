// Topic : DP on Subsequences
// Problem : Subset sum equal to k

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

int main()
{
    vector<int> arr{1, 2, 2, 3};
    int n = arr.size(), k = 3;
    vector<int> previous(k+1, 0);

    for (int ind = 0; ind < n; ind++)
    {
        vector<int> current(k+1, 0);
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
                int notPick = previous[target];
                int pick = 0;
                if(target >= arr[ind]) {
                    pick = previous[target-arr[ind]];
                }
                current[target] = notPick + pick;
            }
        }
        previous = current;
    }
    
    cout<<"Answer : "<<previous[k]<<endl;
    return 0;
}