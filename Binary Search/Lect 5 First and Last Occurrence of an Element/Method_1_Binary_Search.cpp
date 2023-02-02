// Problem : First and Last Occurrence of an Element

// Method 1 : Binary Search

// Time Complexity : O(log(n))

#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int elem) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            ind = mid;
            high = mid-1;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ind;
}

int lastOccurrence(vector<int>& arr, int elem) {
    int low = 0, high = arr.size() - 1, ind = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == elem) {
            ind = mid;
            low = mid+1;
        }
        else if(arr[mid] < elem) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ind;
}

int main(){
    vector<int> arr{2, 4, 10, 10, 10, 18, 20};
    int elem = 10;
    cout<<"First Occurrence of Elem : "<<firstOccurrence(arr, elem)<<endl;
    cout<<"Last Occurrence of Elem : "<<lastOccurrence(arr, elem)<<endl;
    return 0;
}