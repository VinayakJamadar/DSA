// Problem : Finding Peak Element

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : 

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. Peak Element : Element which is greater than its both left and right neighbour

// 3. Criteria for Binary Search on Answer :
//      i. arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]
//      ii. if mid is not required answer, move left if arr[mid-1] > arr[mid] or move right if arr[mid+1] > arr[mid]

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 3, 8, 12, 4, 2};
    int n = arr.size(), low = 0, high = n - 1, ind = -1;
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

    cout<<"Peak Element in given Array is : "<<ind<<endl;
    return 0;
}