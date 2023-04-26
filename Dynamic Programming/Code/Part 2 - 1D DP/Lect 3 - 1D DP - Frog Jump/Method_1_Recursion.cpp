// Topic : 1D DP
// Problem : Maximum sum of non-adjacent elements

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls everytime for calculating the value of f(n)


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n)+O(1))

#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int>& height) {
    // Base Case
    if(ind <= 0) return 0;

    // Recursive Case
    int jumpOne = f(ind-1, height) + abs(height[ind] - height[ind-1]);
    int jumpTwo = INT_MAX;
    if(ind > 1)
        jumpTwo = f(ind-2, height) + abs(height[ind]-height[ind-2]);
    return min(jumpOne, jumpTwo);
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout<<"MinEnergy("<<n<<") : "<<f(n-1, height);
    return 0;
}