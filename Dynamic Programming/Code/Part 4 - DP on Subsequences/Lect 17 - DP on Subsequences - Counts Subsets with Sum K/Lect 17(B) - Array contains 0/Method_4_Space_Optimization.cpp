// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(k+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(k+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(k+1)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(k+1) (i.e O(1) = O(1)+O(k+1))


// Output :
// Answer : 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{0, 0, 1};
    int n = arr.size(), k = 1;
    vector<int> previous(k+1, 0);

    for (int ind = 0; ind < n; ind++)
    {
        vector<int> current(k+1, 0);
        for (int target = 0; target < k+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target == 0 and arr[0] == 0) current[target] = 2;
                else if(target == 0 or arr[0] == target) current[target] = 1;
                else current[target] = 0;
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