#include<bits/stdc++.h>
using namespace std;

bool f(int i, string str){
    if(i >= (str.length()/2)){
        return true;
    }

    if(str[i] != str[str.length()-i-1]) return false;
    return f(i+1, str);
}

int main(){
    string str;
    cin>>str;
    cout<<f(0, str)<<endl;
    return 0;
}