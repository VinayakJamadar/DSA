// Topic : DP on Stocks
// Problem : Buy and Sell Stock II


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
// Maximum Profit : 7

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int>& prices) {
    // Base Case
    if(ind == prices.size()) return 0;

    // Recursive Case
    int pick = 0, notPick = 0;
    // Buy
    if(buy) {
        pick = - prices[ind] + f(ind+1, 0, prices);
        notPick = 0 + f(ind+1, 1, prices);
    }
    // Sell
    else {
        pick = prices[ind] + f(ind+1, 1, prices);
        notPick = 0 + f(ind+1, 0, prices);
    }
    return max(pick, notPick);
}

int main()
{
    vector<int> prices {7,1,5,3,6,4};
    
    cout<<"Maximum Profit : "<<f(0, 1, prices);
    return 0;
}