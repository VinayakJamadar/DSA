// Problem : Binary Search

// Method 1 : Binary Search

// Time Complexity : O(log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0, high = arr.size() - 1, key = 7, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == key) {
            ind = mid;
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