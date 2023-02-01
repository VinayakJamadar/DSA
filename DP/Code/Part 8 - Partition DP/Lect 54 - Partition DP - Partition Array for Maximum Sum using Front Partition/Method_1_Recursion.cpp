// Topic : Partition DP
// Problem : Partition Array for Maximum Sum using Front Partition

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(k^n)
// Reason : As we are calling n recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, int n, vector<int>& arr) {
    // Base Case
    if(i == n) return 0;
    // Recursive Case
    int maxSum = INT_MIN, len = 0, maxElem = INT_MIN;
    for (int j = i; j < min(n, i+k); j++)
    {
        len++;
        maxElem = max(maxElem, arr[j]);
        int sum = (maxElem*len) + f(j+1, k, n, arr);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr{1, 15, 7, 9, 2, 5, 10};
    int n = arr.size(), k = 3;
    cout<<"Answer : "<<f(0, k, n, arr);
    return 0;
}