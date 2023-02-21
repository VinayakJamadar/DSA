// Problem : k Closest Points To Origin

// Time Complexity : O(n*log(k))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<pair<int, int>> arr = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n = arr.size(), k = 2;

    // Solution
    priority_queue<pair<int, pair<int, int>>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({(arr[i].first*arr[i].first) + (arr[i].second*arr[i].second), arr[i]});
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    vector<pair<int, int>> ans(k);

    for (int i = 0; i < k; i++)
    {
        ans[k-i-1] = maxHeap.top().second;
        maxHeap.pop();
    }
    
    cout<<"k Closest Points To Origin are: "<<endl;
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i].first<<", "<<ans[i].second<<endl;
    }
    return 0;
}