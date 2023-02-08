// Problem : Find an Element in a Rotated Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// Steps : 
// 1. Find the smallest element in array (refer Lect 7). Let say minElemInd
// 2. According to value of minElemInd we will use Binary Search Code (refer Lect 1)
//      i. If minElemInd == 0, then Array is not Rotated
//          a. Use Binary Search by keeping low = 0, high = n-1, and if found store it in ind
//      ii. Else, Array is Rotated
//          a. Use Binary Search by keeping low = 0, high = minElemInd-1, if found store it in ind1
//          b. Use Binary Search by keeping low = minElemInd, high = n-1, if found store it in ind2
//          c. Either ind1 or ind2 stored the index of Searched Element 'key'.

#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> arr, int low, int high, int key) {
    int ind = -1;
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
    return ind;
}

int main(){
    vector<int> arr{11, 12, 15, 18, 2, 5, 6, 8};
    int n = arr.size(), low = 0, high = n - 1, minElemInd = 0, key = 15;
    while(low <= high) {
        int mid = (low + high)/2;
        int prev = (mid+n-1)%n;
        if(arr[mid] <= arr[prev]) {
            minElemInd = mid;
            break;
        }
        // Left side of mid is Sorted Array and Right side of mid is Unsorted Array
        else if(arr[0] <= arr[mid]) {
            low = mid+1;
        }
        // Right side of mid is Sorted Array and Left side of mid is Unsorted Array
        else {
            high = mid-1;
        }
    }
    if(minElemInd == 0) {
        int ind = BS(arr, 0, n-1, key);
        if(ind != -1) cout<<"Element is present at index : "<<ind;
        else cout<<"Element not present in array.";
    }
    else {
        int ind1 = BS(arr, 0, minElemInd-1, key);
        int ind2 = BS(arr, minElemInd, n-1, key);
        if(ind1 == -1 and ind2 == -1) cout<<"Element not present in array.";
        else cout<<"Element is present at index : "<<(ind1 != -1 ? ind1 : ind2);
    }
    return 0;
}