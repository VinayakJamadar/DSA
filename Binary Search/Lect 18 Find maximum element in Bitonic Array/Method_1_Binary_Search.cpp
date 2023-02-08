// Problem : Find maximum element in Bitonic Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Bitonic Array : Array which first Monotonic Increase than Monotonic Decrease

// 2. Monotonic means arr[i] and arr[i+1] are never equal

// 3. Bitonic Array has only one Peak Element

// 4. Maximum Element in Bitonic Array is a Peak Element.(So we refer same code of Lect 17)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 3, 8, 12, 4, 2};
    int n = arr.size(), low = 0, high = n - 1, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
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

    cout<<"Peak Element in given Array is : "<<ind<<endl;
    return 0;
}