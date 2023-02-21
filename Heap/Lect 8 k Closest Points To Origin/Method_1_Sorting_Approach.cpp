// Problem : k Closest Points To Origin

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<pair<int, int>> arr = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n = arr.size(), k = 2;

    // Solution
    vector<pair<int, pair<int, int>>> vec(n);

    for (int i = 0; i < n; i++)
    {
        vec[i] = {(arr[i].first*arr[i].first) + (arr[i].second*arr[i].second), arr[i]};
    }
    
    sort(vec.begin(), vec.end());

    vector<pair<int, int>> ans(k);

    for (int i = 0; i < k; i++)
    {
        ans[i] = vec[i].second;
    }
    
    cout<<"k Closest Points To Origin are: "<<endl;
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i].first<<", "<<ans[i].second<<endl;
    }
    return 0;
}