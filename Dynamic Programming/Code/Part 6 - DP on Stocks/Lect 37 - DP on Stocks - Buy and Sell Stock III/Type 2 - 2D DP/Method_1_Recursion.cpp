// Topic : DP on Stocks
// Problem : Buy and Sell Stock III


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
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int transaction, vector<int>& prices) {
    // Base Case
    if(transaction == 4) return 0;
    if(ind == prices.size()) return 0;

    // Recursive Case
    int pick = 0, notPick = 0;
    // Buy
    if(transaction % 2 == 0) {
        pick = - prices[ind] + f(ind+1, transaction+1, prices);
        notPick = 0 + f(ind+1, transaction, prices);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+1, transaction+1, prices);
        notPick = 0 + f(ind+1, transaction, prices);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    
    cout<<"Maximum Profit : "<<f(0, 0, prices);
    return 0;
}