// Problem : Minimum Difference Element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. In Binary Search, if key is not present after existing from 'while' loop
// low points to element which is just greater than 'key' (i.e low points to ceil of key)
// high points to element which is just smaller than 'key' (i.e high points to floor of key)

// 3. Hence if we want to find floor and ceil of 'key' in sorted array
// Just apply binary search, 
// if 'key' is present than 
//      both floor and ceil is 'key' itself
// if 'key' is not present
//      floor of 'key' is = arr[high]
//      ceil of 'key' is = arr[low]

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 3, 8, 10, 15};
    int n = arr.size(), low = 0, high = n - 1, key = 12, ind = -1;
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
    int minDiff = INT_MAX;
    // key is present in array
    if(ind != -1) minDiff = 0;
    // key is not present in array
    else {
        int floor = INT_MAX;
        if(high >= 0) floor = arr[high];
        int ceil = INT_MAX;
        if(low <= n-1) ceil = arr[low];

        if(abs(floor-key) <= abs(ceil-key)) minDiff = floor;
        else minDiff = ceil;
    }
    cout<<"Minimum Difference Element in a Sorted Array is : "<<minDiff<<endl;
    return 0;
}