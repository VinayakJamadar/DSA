// Problem : Search An Element in Bitonic Array

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. Bitonic Array : Array which first Monotonic Increase than Monotonic Decrease

// 3. Monotonic means arr[i] and arr[i+1] are never equal

// 4. Bitonic Array has only one Peak Element

// 5. Maximum Element in Bitonic Array is a Peak Element.(So we refer same code of Lect 17)

// Steps : 

// 1. Find the Index of Maximum Element (i.e Peak Element) in Bitonic Array
// 2. Then arr1 = arr[0,...,ind-1] is Sorted in Ascending Order and arr2 = arr[ind,...,n-1] is Sorted in Descending Order
// 3. Apply BS on arr1 and Reserve BS on arr2

#include<bits/stdc++.h>
using namespace std;

int onAscendingOrder(vector<int>& arr, int key, int low , int high) {
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

int onDescendingOrder(vector<int>& arr, int key, int low , int high) {
    int ind = -1;
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
    vector<int> arr{1, 3, 8, 12, 4, 2};
    int n = arr.size(), low = 0, high = n - 1, key = 10, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(mid > 0 and mid < n-1) {
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) {
                ind = mid;
                break;
            }
            else if(arr[mid-1] > arr[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        else if(mid == 0) {
            if(arr[mid] > arr[mid+1]) {
                ind = 0;
                break;
            }
            else {
                ind = 1;
                break;
            }
        }
        else if(mid == n-1) {
            if(arr[mid] > arr[mid-1]) {
                ind = n-1;
                break;
            }
            else {
                ind = n-2;
                break;
            }
        }
    }

    int ind1 = onAscendingOrder(arr, key, 0, ind-1), ind2 = onDescendingOrder(arr, key, ind, n-1);
    if(ind1 == -1 and ind2 == -1) cout<<"Key "<<key<<" not found in Array.";
    else cout<<"Key "<<key<<" found in Array at index : "<<(ind1 != -1 ? ind1 : ind2); 
    return 0;
}