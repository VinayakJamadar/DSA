// Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

// Problem: Binary Search on Answer for Real Numbers.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<int> a;

bool good(double x) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += floor(a[i]/x);
    }
    return s >= k;
}

int main(){
    cin>>n>>k;

    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double l = 0; // good(l) = 1 i.e l is good
    double r = 1e8; // good(r) = 0 i.e r is bad

    for (int i = 0; i < 100; i++) {
        double m = l + (r-l)/2;
        if(good(m)) {
            l = m;
        }
        else {
            r = m;
        }
        
        // In most of the cases we can use 100 iteration for all standard problem of contest.
        // But Below line code can be used for identifying the number of iterations required for 'for' loop
        // cout<<i<<" "<<l<<" "<<r<<endl;
    }

    cout<<setprecision(20)<<l<<endl;
    return 0;
}