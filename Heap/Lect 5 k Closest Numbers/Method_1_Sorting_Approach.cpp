// Problem : k Closest Numbers

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{6, 5, 9, 7, 8};
    int n = arr.size(), k = 3, x = 7;
    
    // Solution
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = {abs(x-arr[i]), arr[i]};
    }
    
    sort(vec.begin(), vec.end());

    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = vec[i].second;
    }

    cout<<"k Closest Numbers are : [ ";
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}