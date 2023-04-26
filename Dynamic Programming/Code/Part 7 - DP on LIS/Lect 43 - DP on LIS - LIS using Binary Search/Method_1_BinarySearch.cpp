// Topic : DP on LIS
// Problem : Longest Increasing Subsequence using Binary Search

// Method 1 : Using Binary Search (i.e lower_bound function)

// Time Complexity : O(n*log(n))
// Reason : As we are using two nested For Loops


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(n)
// Reason : Using vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(n) (i.e O(1) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : Here temp array elements are not same as original LIS elements. But temp array length is same as original LIS length

int main()
{
    vector<int> arr{1, 7, 8, 4, 5, 6, -1, 9};
    int n = arr.size();

    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    
    cout<<temp.size()<<endl;
    return 0;
}