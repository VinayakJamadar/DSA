// Problem : Ceil (or Lower Bound) of an element in a Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 2. Ceil (or Lower Bound) of 'elem' is Smallest element which is Greater than or equal to 'elem'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, elem = 5, ceilInd = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            ceilInd = mid;
            break;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            ceilInd = mid;
            high = mid-1;
        }
    }
    if(ceilInd == -1) cout<<"Ceil of "<<elem<<" doesn't exist.";
    else cout<<"Ceil of "<<elem<<" is : "<<arr[ceilInd];
    return 0;
}