// Topic : DP on Subsequences
// Problem : Coin Change 2


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
        if(target%coins[ind] == 0) return 1;
        else return 0;
    }

    // Recursive Case
    int pick = 0;
    if(target >= coins[ind]) {
        pick = f(ind, target-coins[ind], coins);
    }
    int notPick = f(ind-1, target, coins);
    return notPick + pick;
}

int main()
{
    vector<int> coins{1, 2, 3};
    int n = coins.size(), reqTarget = 4;
    
    cout<<f(n-1, reqTarget, coins);
    return 0;
}