// Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

// Problem: Binary Search on Answer for Integers.

// Note: Refer Lect 13 and 14 before understanding this.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w, h, n;

bool good(ll x) {
    return (x/w)*(x/h) >= n;
}

int main(){
    cin >> w >> h >> n;

    ll l = 0; // good(l) = 0 i.e l is bad
    ll r = 1; // good(r) = 1 i.e r is good

    while(!good(r)) {
        l = r;
        r *= 2;
    }

    while(l+1 < r) {
        ll m = l + (r-l)/2;
        if(good(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout<<r<<endl;
    return 0;
}