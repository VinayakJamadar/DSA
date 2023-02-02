// Problem : Binary Search

// Method 2 : Optimized Binary Search

// Time Complexity : O(log(n))

// Important Note : Optimized Binary Search is used to Avoid the Integer Overflow while Calculating the mid if low and high both are values near 10^9

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0, high = arr.size() - 1, elem = 7, ind = -1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == elem) {
            ind = mid;
            break;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ind<<endl;
    return 0;
}