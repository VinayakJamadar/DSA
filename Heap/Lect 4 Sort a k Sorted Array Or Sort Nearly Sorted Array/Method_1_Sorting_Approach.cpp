// Problem : Sort a k Sorted Array Or Sort Nearly Sorted Array

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{6, 5, 3, 2, 8, 10, 9};
    int n = arr.size(), k = 3;
    
    // Solution
    sort(arr.begin(), arr.end());

    cout<<"Sorted array is : [ ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
    return 0;
}