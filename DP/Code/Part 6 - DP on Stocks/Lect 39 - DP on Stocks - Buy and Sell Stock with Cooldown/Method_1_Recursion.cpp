// Topic : DP on Stocks
// Problem : Buy and Sell Stock with Cooldown


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

// Answer :
// Maximum Profit : 11

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int>& prices, int n) {
    // Base Case
    if(ind >= n) return 0;

    // Recursive Case
    int pick = 0, notPick = 0;
    // Buy
    if(buy) {
        pick = - prices[ind] + f(ind+1, 0, prices, n);
        notPick = 0 + f(ind+1, 1, prices, n);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+2, 1, prices, n);
        notPick = 0 + f(ind+1, 0, prices, n);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> prices {4, 9, 0, 4, 10};
    int n = prices.size();

    cout<<"Maximum Profit : "<<f(0, 1, prices, n);
    return 0;
}