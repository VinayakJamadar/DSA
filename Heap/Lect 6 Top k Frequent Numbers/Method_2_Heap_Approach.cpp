// Problem : Top k Frequent Numbers

// Time Complexity : O(m*log(min(k, m)))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{1, 1, 1, 3, 2, 2, 4};
    int n = arr.size(), k = 2;

    // Solution
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto &&i : mp)
    {
        minHeap.push({i.second, i.first});
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int m = mp.size();
    vector<int> ans;
    for (int i = 0; i < min(k, m); i++)
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    cout<<"Top k Frequent Numbers are : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}