// Problem : Find Floor of an element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// Floor of 'elem' is Greatest element which is Smaller than or equal to 'elem'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, elem = 5, floorInd = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == elem) {
            floorInd = mid;
            break;
        }
        else if(arr[mid] < elem) {
            floorInd = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(floorInd == -1) cout<<"Floor of "<<elem<<" doesn't exist.";
    else cout<<"Floor of "<<elem<<" is : "<<arr[floorInd];
    return 0;
}