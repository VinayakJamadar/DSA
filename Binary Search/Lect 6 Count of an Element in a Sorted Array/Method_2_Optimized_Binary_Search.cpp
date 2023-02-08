// Problem : Count of an Element in a Sorted Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            ind = mid;
            high = mid-1;
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

int lastOccurrence(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            ind = mid;
            low = mid+1;
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
    vector<int> arr{2, 4, 10, 10, 10, 18, 20};
    int key = 10;
    cout<<"Count of an key : "<<lastOccurrence(arr, key) - firstOccurrence(arr, key) + 1<<endl;
    return 0;
}