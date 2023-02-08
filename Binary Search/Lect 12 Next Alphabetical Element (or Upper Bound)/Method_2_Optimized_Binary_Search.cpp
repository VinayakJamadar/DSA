// Problem : Next Alphabetical Element (or Upper Bound) of an element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. Next Alphabetical Element (or Upper Bound) of 'key' is Smallest element which is Greater than 'key'.

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> arr{'a', 'c', 'f', 'h'};
    int low = 0, high = arr.size() - 1, nextInd = -1;
    char key = 'f';
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            low = mid+1;
        }
        else if(arr[mid] < key) {
            low = mid+1;
        }
        else {
            nextInd = mid;
            high = mid-1;
        }
    }
    if(nextInd == -1) cout<<"Next Alphabetical Element of "<<key<<" doesn't exist.";
    else cout<<"Next Alphabetical Element of "<<key<<" is : "<<arr[nextInd];
    return 0;
}