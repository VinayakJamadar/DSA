// Topic : 1D DP
// Problem : Maximum sum of non-adjacent elements

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

int main(){
    vector<int> arr{2, 1, 4, 9};
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
    
    cout<<"Max Sum of non-adjacent elements : "<<prev;
    return 0;
}