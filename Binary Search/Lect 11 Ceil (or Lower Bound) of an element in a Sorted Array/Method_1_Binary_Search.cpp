// Problem : Ceil (or Lower Bound) of an element in a Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 2. Ceil (or Lower Bound) of 'key' is Smallest element which is Greater than or equal to 'key'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, key = 5, ceilInd = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == key) {
            ceilInd = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid+1;
        }
        else {
            ceilInd = mid;
            high = mid-1;
        }
    }
    if(ceilInd == -1) cout<<"Ceil of "<<key<<" doesn't exist.";
    else cout<<"Ceil of "<<key<<" is : "<<arr[ceilInd];
    return 0;
}