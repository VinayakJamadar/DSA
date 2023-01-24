#include<bits/stdc++.h>
using namespace std;

void f(int ind, vector<int>& arr, vector<int>& subset, vector<vector<int>>& ds) {
    ds.push_back(subset);

    for(int i = ind; i < arr.size(); i++) {
        if(i>ind and arr[i] == arr[i-1]) continue;
        
        subset.push_back(arr[i]);
        f(i+1, arr, subset, ds);
        subset.pop_back();
    }
}

int main(){
    vector<int>v = {1, 2, 2, 3}, s;
    vector<vector<int>> ans;
    f(0, v, s, ans);
    cout<<"[ ";
    for (auto &&i : ans)
    {
        cout<<"[ ";
        for (auto &&j : i)
        {
            cout<<j<<" ";
        }
        cout<<"] ";
    }
    cout<<"]";
    return 0;
}