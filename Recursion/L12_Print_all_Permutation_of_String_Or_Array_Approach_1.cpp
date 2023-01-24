#include<bits/stdc++.h>
using namespace std;

void f(vector<int>& arr, vector<int>& prem, vector<bool>& status, vector<vector<int>>& ds){
    if(prem.size() == arr.size()){
        ds.push_back(prem);
        return;
    }

    for (int i = 0; i < status.size(); i++)
    {
        if(status[i] == 0){
            prem.push_back(arr[i]);
            status[i] = 1;
            f(arr, prem, status, ds);
            prem.pop_back();
            status[i] = 0;
        }
    }
}

int main(){
    vector<int> a = {1, 2, 3}, p;
    vector<bool> s = {0, 0, 0};
    vector<vector<int>> ans;
    f(a, p, s, ans);
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