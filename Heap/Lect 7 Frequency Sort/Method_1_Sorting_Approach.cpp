// Problem : Top k Frequent Numbers

// Time Complexity : O(m*log(m))

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

    vector<pair<int, int>> vec;
    for (auto &&i : mp)
    {
        vec.push_back({i.second, i.first});
    }
    
    int m = mp.size();
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int freq = vec[i].first;
        int elem = vec[i].second;
        for (int i = 0; i < freq; i++)
        {
            ans.push_back(elem);
        }
    }

    cout<<"Top k Frequent Numbers are : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}