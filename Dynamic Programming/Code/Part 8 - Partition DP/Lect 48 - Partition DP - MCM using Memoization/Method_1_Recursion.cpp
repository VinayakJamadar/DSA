// Topic : Partition DP
// Problem : Matrix Chain Multiplication

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(n^n)
// Reason : As we are calling n recursive calls for n times


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& arr) {
    // Base Case
    if(i == j) return 0;
    // Recursive Case
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(i, k, arr) + f(k+1, j, arr);
        mini = min(mini, steps);
    }
    return mini;
}

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int n = arr.size();
    cout<<"Answer : "<<f(1, n-1, arr);
    return 0;
}