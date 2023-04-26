// Topic : 1D DP
// Problem : Climbing Stairs

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

int f(int n) {
    if(n <= 2) return n;
    return f(n-1)+f(n-2);
}

int main(){
    int n = 3;
    cout<<"Ways("<<n<<") : "<<f(n);
    return 0;
}