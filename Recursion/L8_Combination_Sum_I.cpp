#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

void f(int ind, vector<int>& ds, int target, int arr[], int n){
    // if(target == 0) {
    //     v.push_back(ds);
    //     return;
    // }
    if(ind == n) {
        if(target == 0) v.push_back(ds);
        return ;
    }

    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        f(ind, ds, target-arr[ind], arr, n);
        ds.pop_back();
    }

    f(ind+1, ds, target, arr, n);
}

int main(){
    int arr[] = {2, 3, 6, 7};
    vector<int> ds;
    f(0, ds, 7, arr, 4);
    cout<<"[ ";
    for (auto &&i : v)
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