// Topic : 1D DP
// Problem : Frog Jump with K Jumps

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(k ^ n)
// Reason : As we are calling k recursive calls everytime for calculating the value of f(n)


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n)+O(1))

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int k, vector<int>& height) {
    if(ind <= 0) return 0;
    int minJump = INT_MAX;
    for(int i = 1; i <= k; i++) {
        int ithJump = INT_MAX;
        if(ind-i >= 0) {
            ithJump = f(ind-i, k, height) + abs(height[ind] - height[ind-i]);
        }
        minJump = min(minJump, ithJump);
    }
    return minJump;
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size(), k = 2;;
    cout<<"MinEnergy("<<n<<") : "<<f(n-1, k, height);
    return 0;
}