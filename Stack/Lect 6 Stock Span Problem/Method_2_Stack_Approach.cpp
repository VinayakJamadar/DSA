// Problem: Stock Span Problem
// Find the Consecutive Smaller or Equal Before it (i.e at Left side)

// Method 2: Stack Approach

// Time Complexity: O(n)
// Reason: At worst case 'for' loop iterate 'n' times.

// Space Complexity: O(n)
// Reason: Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'n' elements of 'arr' array.

// Algorithm:
// 1. Find NGL Index array (nglIndex)
// 2. Then answer[i] = i - nglIndex[i]

// Note:
// In Lect 3 NGL, for 'ngl' array we kept 'Nearest Greater Element to Left' in Stack
// But in this Lect, for 'nglIndex' we kept 'Index of Nearest Greater Element to Left' in Stack

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{100, 80, 60, 70, 60, 75, 85};

    int n = arr.size();
    
    vector<int> nglIndex;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = 0; i < n; i++) {
        if(st.empty()) {
            nglIndex.push_back(-1);
        }
        else if(!st.empty() && arr[st.top()] > arr[i]) {
            nglIndex.push_back(st.top());
        }
        else if(!st.empty() && arr[st.top()] <= arr[i]) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nglIndex.push_back(-1);
            }
            else {
                nglIndex.push_back(st.top());
            }
        }
        st.push(i);
    }

    // My Code
    // for (int i = 0; i < n; i++) {
    //     while(!st.empty() && arr[st.top()] <= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         nglIndex.push_back(-1);
    //     }
    //     else {
    //         nglIndex.push_back(st.top());
    //     }
    //     st.push(i);
    // }

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