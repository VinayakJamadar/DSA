// Problem : Index of First 1 in a Binary Sorted Infinite Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. This problem is combination of two problems :
//      i. First Occurance of an Element (here key = 1) (Refer Lect 5)
//      ii. Find position of an element (here key = 1) in an Infinite Sorted Array (Refer Lect 13)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int low = 0, high = 1, key = 1, ind = -1;

    while(key > arr[high]) {
        low = high;
        high = high * 2;
    }

    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            ind = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    if(ind == -1) cout<<"1 is not present in array.";
    else cout<<"First 1 is present at index : "<<ind<<endl;
    return 0;
}