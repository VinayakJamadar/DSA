// Topic : DP on Stocks
// Problem : Buy and Sell Stock III


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*2*3)
// Reason : As we are using three nested For Loops (n, 2 and 3 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(2*3)
// Reason : Using vector data structure of 2*3 size

// Total Space Complexity : O(2*3)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(2*3) (i.e O(1) = O(1)+O(2*3))

// Answer :
// Maximum Profit : 6

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : To simplify Base Case we shifted dp index by 1 (i.e n to n+1)

int main()
{
    vector<int> prices {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size(), cnt = 2;
    vector<vector<int>> front(2, vector<int> (cnt+1, -1)), current(2, vector<int> (cnt+1, -1));

    for (int ind = n; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 0; cap < cnt+1; cap++)
            {
                // Base Case
                if(ind == n) current[buy][cap] = 0;
                // Base Case
                else if(cap == 0) current[buy][cap] = 0;
                // Recursive Case
                else {
                    int pick = 0, notPick = 0;
                    // Buy
                    if(buy) {
                        pick = - prices[ind] + front[0][cap];
                        notPick = 0 + front[1][cap];
                    }
                    // Sell
                    else {
                        pick = prices[ind] + front[1][cap-1];
                        notPick = 0 + front[0][cap];
                    }
                    current[buy][cap] = max(pick, notPick);
                }
            }
        }
        front = current;
    }
    
    cout<<"Maximum Profit : "<<front[1][cnt];
    return 0;
}