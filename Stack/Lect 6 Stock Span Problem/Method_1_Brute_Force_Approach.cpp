// Problem: Stock Span Problem
// Find the Consecutive Smaller or Equal Before it (i.e at Left side)

// Method 1: Brute Force (i.e using 2 Nested 'for' loop) Approach

// Time Complexity: O(n^2)
// Reason: Using 2 Nested 'for' loop.

// Space Complexity: O(1)
// Reason: Not using any Data Structure

// Algorithm:
// 1. Find NGL Index array (nglIndex)
// 2. Then answer[i] = i - nglIndex[i]

// Note:
// In Lect 3 NGL, for 'nglIndex' array we kept 'Nearest Greater Element to Left' in Stack
// But in this Lect, for 'nglIndex' we kept 'Index of Nearest Greater Element to Left' in Stack

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{100, 80, 60, 70, 60, 75, 85};

    int n = arr.size();
    
    vector<int> nglIndex(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if(arr[j] > arr[i]) {
                nglIndex[i] = j;
                break;
            }
        }
    }

    cout << "NGL Index: [ ";
    for (int i = 0; i < n; i++) {
        cout << nglIndex[i] << " ";
    }
    cout << "]" << endl;
    
    vector<int> ans(n);
    cout << "Answer: [ ";
    for (int i = 0; i < n; i++) {
        ans[i] = i - nglIndex[i];
        cout << ans[i] << " ";
    }
    cout << "]";
    return 0;
}