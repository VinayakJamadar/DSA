// Topic : 1D DP
// Problem : Frog Jump

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
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int prev2 = 0, prev = 0;
    for(int ind = 1; ind < n; ind++) {
        int jumpOne = prev + abs(height[ind] - height[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1)
            jumpTwo = prev2 + abs(height[ind]-height[ind-2]);
        int cur = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur;
    }
    cout<<"MinEnergy("<<n<<") : "<<prev;
    return 0;
}