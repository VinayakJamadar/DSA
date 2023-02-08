// Problem : Find Floor of an element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// Floor of 'key' is Greatest element which is Smaller than or equal to 'key'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, key = 5, floorInd = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            floorInd = mid;
            break;
        }
        else if(arr[mid] < key) {
            floorInd = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(floorInd == -1) cout<<"Floor of "<<key<<" doesn't exist.";
    else cout<<"Floor of "<<key<<" is : "<<arr[floorInd];
    return 0;
}