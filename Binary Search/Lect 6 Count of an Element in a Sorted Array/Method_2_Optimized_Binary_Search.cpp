// Problem : Count of an Element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int elem) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == elem) {
            ind = mid;
            high = mid-1;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ind;
}

int lastOccurrence(vector<int>& arr, int elem) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == elem) {
            ind = mid;
            low = mid+1;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ind;
}

int main(){
    vector<int> arr{2, 4, 10, 10, 10, 18, 20};
    int elem = 10;
    cout<<"Count of an Elem : "<<lastOccurrence(arr, elem) - firstOccurrence(arr, elem) + 1<<endl;
    return 0;
}