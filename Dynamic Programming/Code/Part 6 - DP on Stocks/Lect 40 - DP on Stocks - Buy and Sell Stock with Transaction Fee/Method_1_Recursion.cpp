// Topic : DP on Stocks
// Problem : Buy and Sell Stock with Transaction Fee


// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

// Answer :
// Maximum Profit : 3

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int>& prices, int fee) {
    // Base Case
    if(ind == prices.size()) return 0;

    // Recursive Case
    int pick = 0, notPick = 0;
    // Buy
    if(buy) {
        pick = - prices[ind] + f(ind+1, 0, prices, fee);
        notPick = 0 + f(ind+1, 1, prices, fee);
    }
    // Sell
    else {
        pick = prices[ind] - fee + f(ind+1, 1, prices, fee);
        notPick = 0 + f(ind+1, 0, prices, fee);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> prices{1, 3, 5, 6};
    int n = prices.size(), fee = 2;
    
    cout<<"Maximum Profit : "<<f(0, 1, prices, fee);
    return 0;
}