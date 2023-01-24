#include<bits/stdc++.h>
using namespace std;

void f(int ind, vector<int>& arr, vector<vector<int>>& ds) {
    if(ind == arr.size()) {
        ds.push_back(arr);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        f(ind+1, arr, ds);
        swap(arr[ind], arr[i]);
    }
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> ans;
    f(0, a, ans);
    // cout<<"[ ";
    // for (auto &&i : ans)
    // {
    //     cout<<"[ ";
    //     for (auto &&j : i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"] ";
    // }
    // cout<<"]";
    // for (auto &&i : ans)
    // {
    //     cout<<"[ ";
    //     for (auto &&j : i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"]"<<endl;
    // }
    int n = a.size();
    for (int i = 0; i < ans.size(); i++)
    {
        int arr[n-2], cnt = 0, x = 0, y = 0, z = 0;
        cout<<"[ ";
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"] --> "<<i+1<<" --> ";
        for (int j = 1; j < n-1; j++)
        {
            if(ans[i][j-1]<ans[i][j] and ans[i][j]>ans[i][j+1]) {
                // arr[cnt] = 0;
                cout<<0<<" ";
                x++;
            }
            else if(ans[i][j-1]>ans[i][j] and ans[i][j]<ans[i][j+1]) {
                // arr[cnt] = 1;
                cout<<1<<" ";
                y++;
            }
            else {
                // arr[cnt] = -1;
                cout<<-1<<" ";
                z++;
            }
        }
        cout<<" --> a = "<<x<<" b = "<<y<<endl;
        // cout<<" --> "<<x<<" "<<y<<" "<<z<<" "<<endl;
    }
    
    return 0;
}