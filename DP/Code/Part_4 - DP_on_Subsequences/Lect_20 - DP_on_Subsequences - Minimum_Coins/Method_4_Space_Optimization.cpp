// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*(maxW+1))
// Reason : As we are using two nested For Loops (n and k+1 iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(maxW+1)
// Reason : Using vector data structure of k+1 size

// Total Space Complexity : O(maxW+1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(maxW+1) (i.e O(1) = O(1)+O(maxW+1))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> coins{1, 6, 5, 9};
    int n = coins.size(), reqTarget = 11;
    vector<int> previous(reqTarget+1, -1);

    for (int ind = 0; ind < n; ind++)
    {
        vector<int> current(reqTarget+1, -1);
        for (int target = 0; target < reqTarget+1; target++)
        {
            // Base Case
            if(ind == 0) {
                if(target%coins[ind] == 0) current[target] = target/coins[ind];
                else current[target] = 1e9;
            }
            // Recursive Case
            else {
                int notPick = 0 + previous[target];
                int pick = INT_MAX;
                if(target >= coins[ind]) {
                    pick = 1 + current[target-coins[ind]];
                }
                current[target] = min(pick, notPick);
            }
        }
        previous = current;
    }
    
    int ans = previous[reqTarget];
    if(ans >= 1e9) cout<<"Answer : -1";
    else cout<<"Answer : "<<ans;
    return 0;
}