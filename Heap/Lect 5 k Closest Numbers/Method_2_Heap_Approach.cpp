// Problem : k Closest Numbers

// Time Complexity : O(n*log(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{6, 5, 9, 7, 8};
    int n = arr.size(), k = 3, x = 7;

    // Solution
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({abs(x-arr[i]), arr[i]});
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = maxHeap.top().second;
        maxHeap.pop();
    }

    cout<<"k Closest Numbers are : [ ";
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}