// Topic : Partition DP
// Problem : Palindrome Partitioning - II using Front Partitioning 

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

bool isPalindrome(int i, int j, string& str)
{
    while(i < j) {
        if(str[i] != str[j]) return 0;
        i++, j--;
    }
    return 1;
}

int f(int i, int n, string& str) {
    // Base Case
    if(i == n) return 0;
    // Recursive Case
    int minCuts = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if(isPalindrome(i, j, str)) {
            int cuts = 1 + f(j+1, n, str);
            minCuts = min(minCuts, cuts);
        }
    }
    return minCuts;
}

int main()
{
    string str = "ABBAC";
    int n = str.size();
    cout<<"Minimum Cuts : "<<f(0, n, str)-1;
    return 0;
}