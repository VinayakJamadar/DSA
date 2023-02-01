// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxilliary Space Complexity : O(n)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxilliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(n) and Non-Auxilliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))


// Output :
// Answer : 1

#include <bits/stdc++.h>
using namespace std;

// Approach :
// As given in problem we have to partition set into two subset s1 (sum of subset1) and s2 (sum of subset2), where s1 > s2
// Consider 
// s1 - s2 = d  ...... eqn 1 
// s1 + s2 = totalSum ...... eqn 2
// eqn 2 can be written as
// then s1 = totalSum - s2 ...... eqn 3
// put eqn 3 in eqn 1
// totalSum - s2 - s2 = d
// totalSum - 2*s2 = d
// i.e s2 = (totalSum - d)/2 ..... eqn 4

// Two Edge Cases of eqn 4
// 1. totalSum - d is negative (i.e totalSum - d < 0) --> Reason : not possible
// 2. totalSum - d is odd --> Reason : If totalSum - d is odd then (totalSum-d)/2 which gives decimal value and As array elements are integer so value can't be a decimal

int f(int ind, int target, vector<int>& arr) {
    // Base Case
    if(ind == 0) {
        if(target == 0 and arr[0] == 0) return 2;
        else if(target == 0 or arr[0] == target) return 1;
        else return 0;
    }

    // Recursive Case
    int notPick = f(ind-1, target, arr);
    int pick = 0;
    if(target >= arr[ind]) {
        pick = f(ind-1, target-arr[ind], arr);
    }
    return notPick + pick;
}

int main()
{
    vector<int> arr{5, 2, 6, 4};
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0), d = 3;

    int answer;
    if((totalSum-d < 0) or (totalSum-d)%2) answer = 0;
    else {
        int k = (totalSum - d)/2;
        answer = f(n-1, k, arr);
    }
    cout<<"Answer : "<<answer;
    return 0;
}