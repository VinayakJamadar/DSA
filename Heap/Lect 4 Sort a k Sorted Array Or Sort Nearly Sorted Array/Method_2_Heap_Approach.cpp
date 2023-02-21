// Problem : Sort a k Sorted Array Or Sort Nearly Sorted Array

// Time Complexity : O(n*log(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{6, 5, 3, 2, 8, 10, 9};
    int n = arr.size(), k = 3;

    // Solution
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    cout<<"Sorted is array: [ ";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}