// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(maxW+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(maxW+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(maxW+1)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(maxW+1) (i.e O(1) = O(1)+O(maxW+1))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins{1, 2, 3};
    int n = coins.size(), reqTarget = 4;
    vector<int> previous(reqTarget+1, -1);

    for (int ind = 0; ind < n; ind++)
    {
        vector<int> current(reqTarget+1, -1);
        for (int target = 0; target < reqTarget+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target%coins[ind] == 0) current[target] = 1;
                else current[target] = 0;
            }
            // Recursive Case
            else {
                int notPick = previous[target];
                int pick = 0;
                if(target >= coins[ind]) {
                    pick = current[target-coins[ind]];
                }
                current[target] = notPick + pick;
            }
        }
        previous = current;
    }
    
    cout<<previous[reqTarget];
    return 0;
}