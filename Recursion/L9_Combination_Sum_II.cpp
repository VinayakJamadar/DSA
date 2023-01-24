#include<bits/stdc++.h>
using namespace std;

void f(int ind, vector<int>& ds, vector<vector<int>>& ans, int target, vector<int>& arr){
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if(i > ind and arr[i]==arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        f(i+1, ds, ans, target-arr[i], arr);
        ds.pop_back();
    }
}

int main(){
    vector<int> ds, arr = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());
    f(0, ds, ans, 8, arr);
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