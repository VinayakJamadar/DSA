// Topic : DP on Stocks
// Problem : Buy and Sell Stock


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n)
// Reason : As we are using For Loops (n iterations)


// Auxilliary Space Complexity : O(1)
// Reason : No Auxilliary space

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(1) (i.e O(1) = O(1)+O(1))

// Answer :
// Maximum Profit : 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {7,1,5,3,6,4};
    int maxProfit = 0;
	int mini = arr[0];
	
    for (int i = 1; i < arr.size(); i++)
    {
        int currentProfit = arr[i] - mini;
        maxProfit = max(maxProfit, currentProfit);
        mini = min(mini, arr[i]);
    }
    
    cout<<"Maximum Profit : "<<maxProfit;
    return 0;
}