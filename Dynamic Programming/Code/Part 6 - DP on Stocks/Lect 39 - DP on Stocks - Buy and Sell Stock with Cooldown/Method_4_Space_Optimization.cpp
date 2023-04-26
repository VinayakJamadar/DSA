// Topic : DP on Stocks
// Problem : Buy and Sell Stock with Cooldown


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*2)
// Reason : As we are using two nested For Loops (n and 2 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(2)
// Reason : Using vector data structure of 2 size

// Total Space Complexity : O(2)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(2) (i.e O(1) = O(1)+O(2))

// Answer :
// Maximum Profit : 11

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : To simplify Base Case we shifted dp ind by 2(i.e n to n+2)

int main()
{
    vector<int> prices {4, 9, 0, 4, 10};
    int n = prices.size();
    vector<int> front2(2, -1), front1(2, -1), current(2, -1);

    // Base Case
    front1[0] = 0, front1[1] = 0;
    front2[0] = 0, front2[1] = 0;

    // Recursive Case
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int pick = 0, notPick = 0;
            // Buy
            if(buy) {
                pick = - prices[ind] + front1[0];
                notPick = 0 + front1[1];
            }
            // Sell
            else {
                pick = prices[ind] + front2[1];
                notPick = 0 + front1[0];
            }
            current[buy] = max(pick, notPick);
        }
        front2 = front1;
        front1 = current;
    }
    
    cout<<"Maximum Profit : "<<front1[1]<<endl;
    return 0;
}