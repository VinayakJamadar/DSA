// Topic : 1D DP
// Problem : Frog Jump with K Jumps

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n * k)
// Reason : As we are using two nested For Loops. Outer For Loop with n iterations and Inner For Loop with k iterations.


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(k)
// Reason : Using of deque data structure of size k

// Total Space Complexity : O(k)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(k) (i.e O(k) = O(1)+O(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size(), k = 2;
    deque<int> prev(k, 0);
    for (int ind = 1; ind < n; ind++)
    {
        int cur = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            int ithJump = INT_MAX;
            if(ind-i >= 0) {
                ithJump = prev[i-1] + abs(height[ind] - height[ind-i]);
            }
            cur = min(cur, ithJump);
        }
        
        prev.pop_front();
        prev.push_back(cur);
    }
    
    cout<<"MinEnergy("<<n<<") : "<<prev[k-1];
    return 0;
}