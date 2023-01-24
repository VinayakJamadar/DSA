// Topic : 1D DP
// Problem : House Robber

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n)
// Reason : As we are using a For Loop of n iterations


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(1)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(1) (i.e O(1) = O(1)+O(1))

#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int>& arr) {
    int n = arr.size();
    int prev2 = 0, prev = arr[0];

    for (int ind = 1; ind < n; ind++)
    {
        int pick = arr[ind];
        if(ind > 1) pick += prev2;
        
        int notPick = 0 + prev;
        int cur = max(pick, notPick);

        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main(){
    vector<int> valueInHouse{2, 3, 2};
    int len = valueInHouse.size();
    if(len == 1) {
        cout<<"Ans : "<<valueInHouse[0];
    }
    else {
        // temp1 --> Contains all the elements of 'valueInHouse' except first element
        // temp2 --> Contains all the elements of 'valueInHouse' except last element
        vector<int> temp1, temp2;
        for (int i = 0; i < len; i++)
        {
            if(i != 0) temp1.push_back(valueInHouse[i]);
            if(i != len-1) temp2.push_back(valueInHouse[i]);
        }
        
        cout<<"Ans : "<<max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
    return 0;
}