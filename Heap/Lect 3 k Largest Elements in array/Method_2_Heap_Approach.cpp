// Problem : k Largest Elements in array

// Time Complexity : O(n*log(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{7, 10, 4, 3, 20, 15};
    int n = arr.size(), k = 3;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = minHeap.top();
        minHeap.pop();
    }
    cout<<"k Largest Elements is array: [ ";
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}