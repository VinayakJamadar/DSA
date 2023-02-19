// Problem : kth Smallest Element

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{7, 10, 4, 3, 20, 15};
    int n = arr.size(), k = 3;
    sort(arr.begin(), arr.end());
    cout<<"kth Smallest Element is: "<<arr[k-1];
    return 0;
}