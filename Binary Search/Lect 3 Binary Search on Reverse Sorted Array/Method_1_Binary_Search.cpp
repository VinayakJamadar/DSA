// Problem : Binary Search on Reverse Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int low = 0, high = arr.size() - 1, elem = 5, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            ind = mid;
            break;
        }
        else if(arr[mid] > elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ind<<endl;
    return 0;
}