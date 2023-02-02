// Problem : Number of Times a Sorted Array is Rotated (Left or Right)

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 1. Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

// 2. Index Smallest or Minimum element in rotated array is that element which is smallest than both previous and next element.

// 3. Number of Times a Sorted Array in Rotated
//      i. Left Rotated : (Size of Array) - (Index of Smallest Element)
//      ii. Right Rotated : (Index of Smallest Element)

// Steps : 
// 1. Calculate mid = (low + high)/2

// 2. Check
// If arr[mid] is smallest element than return 'mid'

// 3. Else repeat Step 1 and Step 2 in Unsorted side from 'mid'
// If arr[0] <= arr[mid] than Right side is Unsorted array. So set low = mid+1
// Else Left side is Unsorted array. So set high = mid-1

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{11, 12, 15, 18, 2, 5, 6, 8};
    int n = arr.size(), low = 0, high = n - 1, ind = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        int prev = (mid+n-1)%n;
        if(arr[mid] <= arr[prev]) {
            ind = mid;
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
    if(ind == 0) {
        cout<<"Array is not Rotated"<<endl;
    }
    else {
        cout<<"Number of Times a Sorted Array is Rotated : "<<endl;
        cout<<"If Left Rotated : "<<n-ind<<endl;
        cout<<"If Right Rotated : "<<ind<<endl;
    }
    return 0;
}