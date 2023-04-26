// Topic : 1D DP
// Problem : Frog Jump

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

int f(int ind, vector<int>& arr) {
    if(ind == 0) return arr[0];
    if(ind < 0) return 0;
    
    int pick = arr[ind] + f(ind-2, arr);
    int notPick = 0 + f(ind-1, arr);
    return max(pick, notPick);
}

int main(){
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    cout<<"Max Sum of non-adjacent elements : "<<f(n-1, arr);
    return 0;
}