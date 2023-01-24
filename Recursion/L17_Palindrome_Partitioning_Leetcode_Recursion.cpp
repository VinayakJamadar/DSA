#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    while(start<=end) {
        if(str[start] != str[end]) return false;
        ++start, --end;
    }
    return true;
}

void partition(int index, string str, vector<string>& path, vector<vector<string>>& res) {
    if(index == str.size()) {
        res.push_back(path);
        return;
    }

    for (int i = index; i < str.size(); i++)
    {
        if(isPalindrome(str, index, i)) {
            path.push_back(str.substr(index, i-index+1));
            partition(i+1, str, path, res);
            path.pop_back();
        }
    }
}

int main(){
    vector<vector<string>> res;
    vector<string> path;
    string str = "aabb";

    partition(0, str, path, res);
    
    cout<<"[ ";
    for (auto &&i : res)
    {
        cout<<"[ ";
        for (auto &&j : i)
        {
            cout<<"\""<<j<<"\" ";
        }
        cout<<"] ";
    }
    cout<<"]";
    
    return 0;
}