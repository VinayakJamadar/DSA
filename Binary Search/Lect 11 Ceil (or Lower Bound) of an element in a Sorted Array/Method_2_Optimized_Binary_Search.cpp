// Problem : Ceil (or Lower Bound) of an element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. Ceil (or Lower Bound) of 'elem' is Smallest element which is Greater than or equal to 'elem'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, elem = 5, ceilInd = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == elem) {
            ceilInd = mid;
            break;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            ceilInd = mid;
            high = mid-1;
        }
    }
    if(ceilInd == -1) cout<<"Ceil of "<<elem<<" doesn't exist.";
    else cout<<"Ceil of "<<elem<<" is : "<<arr[ceilInd];
    return 0;
}