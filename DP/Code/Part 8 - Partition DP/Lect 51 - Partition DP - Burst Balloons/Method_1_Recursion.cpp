// Topic : Partition DP
// Problem : Burst Balloons

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(n^n)
// Reason : As we are calling n recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE :

// 1. Reason for inserting 1 at front
// To get the previous balloon size for first element

// 2. Reason for inserting 2 at back
// To get the next balloon size for last element

int f(int i, int j, vector<int>& a) {
    // Base Case
    if(i > j) return 0;
    // Recursive Case
    int maxi = INT_MIN;
    for (int k = i; k <= j; k++)
    {
        int coins = (a[i-1]*a[k]*a[j+1]) + f(i, k-1, a) + f(k+1, j, a);
        maxi = max(maxi, coins);
    }
    return maxi;
}

int main()
{
    vector<int> a{7, 1, 8};
    int n = a.size();
    // Inserting 1 at front
	a.insert(a.begin(), 1);
    // Inserting 1 at back
	a.push_back(1);
    cout<<"Answer"<<f(1, n, a);
    return 0;
}