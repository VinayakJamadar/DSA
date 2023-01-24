#include<bits/stdc++.h>
using namespace std;

void f(int ind, vector<int>& v, vector<int>& s, int sum){
    if(ind == v.size()){
        s.push_back(sum);
        return;
    }

    f(ind+1, v, s, sum+v[ind]);
    f(ind+1, v, s, sum);
}

int main(){
    vector<int> vr = {3, 1, 2}, st;
    f(0, vr, st, 0);
    sort(st.begin(), st.end());
    cout<<"[ ";
    for (auto &&i : st)
    {
        cout<<i<<" ";
    }
    cout<<"]";
    return 0;
}