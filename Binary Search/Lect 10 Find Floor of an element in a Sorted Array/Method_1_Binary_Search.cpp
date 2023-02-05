// Problem : Find Floor of an element in a Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

// Important Note :

// Floor of 'elem' is Greatest element which is Smaller than or equal to 'elem'

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 8, 9, 10, 10, 12, 19};
    int low = 0, high = arr.size() - 1, elem = 5, floorInd = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            floorInd = mid;
            break;
        }
        else if(arr[mid] < elem) {
            floorInd = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(floorInd == -1) cout<<"Floor of "<<elem<<" doesn't exist.";
    else cout<<"Floor of "<<elem<<" is : "<<arr[floorInd];
    return 0;
}