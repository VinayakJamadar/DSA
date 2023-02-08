// Problem : Order Not Known Binary Search

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

#include<bits/stdc++.h>
using namespace std;

int onAscendingOrder(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, ind = -1;
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

int onDescendingOrder(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) {
            ind = mid;
            break;
        }
        else if(arr[mid] > key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ind;
}

int main(){
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int key = 5;
    if(arr[0] < arr[arr.size()-1]) cout<<onAscendingOrder(arr, key);
    else cout<<onDescendingOrder(arr, key);
    return 0;
}