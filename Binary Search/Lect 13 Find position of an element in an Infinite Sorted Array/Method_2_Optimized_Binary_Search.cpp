// Problem : Find position of an element in an Infinite Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. In Binary Search 'key' or 'searching element' is always bounded between the low and high indices

// 3. In Infinite Sorted Array the value of low = 0. But Issue is 'What is the value of high'

// Steps :

// 1. To find value of high. We first set high = 1
// 2. while(key > arr[high]) low = high, high = high * 2
// 3. After existing the while loop, We will simply apply Binary Search on new values of low and high

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Step 1. Set high = 1
    int low = 0, high = 1, key = 7, ind = -1;

    // Step 2.
    while(key > arr[high]) {
        low = high;
        high = high * 2;
    }

    // Step 3. Simply apply Binary Search on new values of low and high
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            ind = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(ind == -1) cout<<"Element "<<key<<" is not present in array.";
    else cout<<"Element "<<key<<" is present at index : "<<ind<<endl;
    return 0;
}