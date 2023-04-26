// Topic : Introduction to DP
// Problem : Finding nth Fibonacci Number(were n is 0 indexed).

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n)
// Reason : As we are using a For Loop of n iterations


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(1)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(1) (i.e O(1) = O(1)+O(1))

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int prev2 = 0, prev = 1;
    for(int i = 2; i <= n; i++) {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    cout<<"Fibonacci("<<n<<") : "<<prev;
    return 0;
}