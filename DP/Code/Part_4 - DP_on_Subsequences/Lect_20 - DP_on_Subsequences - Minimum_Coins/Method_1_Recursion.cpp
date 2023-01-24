// Topic : DP on Subsequences
// Problem : Minimum Coins


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^max(n, k)) , where k = reqTarget/minElementOf(coins)
// Reason : As we are calling 2 recursive calls for max(n, k) times


// Auxilliary Space Complexity : O(max(n, k)) , where k = reqTarget/minElementOf(coins)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(max(n, k)) , where k = reqTarget/minElementOf(coins)
// Reason : Sum of Auxilliary Space Complexity O(max(n, k)) and Non-Auxilliary Space Complexity O(1) (i.e O(max(n, k)) = O(max(n, k)) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int target, vector<int>& coins) {
    // Base Case
    if(ind == 0) {
        if(target%coins[ind] == 0) return target/coins[ind];
        else return 1e9;
    }

    // Recursive Case
    int notPick = 0 + f(ind-1, target, coins);
    int pick = INT_MAX;
    if(target >= coins[ind]) {
        pick = 1 + f(ind, target-coins[ind], coins);
    }
    return min(pick, notPick);
}

int main()
{
    vector<int> coins{1, 6, 5, 9};
    int n = coins.size(), reqTarget = 11;
    
    int ans = f(n-1, reqTarget, coins);
    if(ans >= 1e9) cout<<"Answer : -1";
    else cout<<"Answer : "<<ans;
    return 0;
}