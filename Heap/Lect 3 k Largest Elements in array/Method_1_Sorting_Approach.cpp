// Problem : k Largest Elements in array

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{7, 10, 4, 3, 20, 15};
    int n = arr.size(), k = 3;

    // Solution
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = arr[i];
    }
    cout<<"k Largest Elements is array: [ ";
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}