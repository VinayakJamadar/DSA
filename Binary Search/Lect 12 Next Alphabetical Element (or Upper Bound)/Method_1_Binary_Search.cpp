// Problem : Next Alphabetical Element (or Upper Bound) of an element in a Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

// Important Note :

// 2. Next Alphabetical Element (or Upper Bound) of 'elem' is Smallest element which is Greater than 'elem'.

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> arr{'a', 'c', 'f', 'h'};
    int low = 0, high = arr.size() - 1, nextInd = -1;
    char elem = 'f';
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            low = mid+1;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            nextInd = mid;
            high = mid-1;
        }
    }
    if(nextInd == -1) cout<<"Next Alphabetical Element of "<<elem<<" doesn't exist.";
    else cout<<"Next Alphabetical Element of "<<elem<<" is : "<<arr[nextInd];
    return 0;
}