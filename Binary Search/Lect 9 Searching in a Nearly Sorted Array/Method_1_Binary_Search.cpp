// Problem : Searching in a Nearly Sorted Array

// Method 1 : Binary Search

// Time Complexity : O(log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{5, 10, 30, 20, 40};
    int low = 0, high = arr.size() - 1, key = 20, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == key) {
            ind = mid;
            break;
        }
        else if(mid-1 >= low and arr[mid-1] == key) {
            ind = mid-1;
            break;
        }
        else if(mid+1 <= high and arr[mid+1] == key) {
            ind = mid+1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ind<<endl;
    return 0;
}