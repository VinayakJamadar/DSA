// Problem : kth Smallest Element

// Time Complexity : O(n*log(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{7, 10, 4, 3, 20, 15};
    int n = arr.size(), k = 3;

    // Solution
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    cout<<"kth Smallest Element is: "<<maxHeap.top();
    return 0;
}