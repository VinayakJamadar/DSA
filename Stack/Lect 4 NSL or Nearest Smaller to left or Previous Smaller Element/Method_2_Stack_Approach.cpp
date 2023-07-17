// Problem: NSL or Nearest Smaller to left or Previous Smallest Element

// Method 2: Stack Approach

// Time Complexity: O(n)
// Reason: At worst case 'for' loop iterate 'n' times.

// Space Complexity: O(n)
// Reason: Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'n' elements of 'arr' array.

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{4, 5, 2, 10, 8};

    int n = arr.size();
    
    vector<int> nsl;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = 0; i < n; i++) {
        if(st.empty()) {
            nsl.push_back(-1);
        }
        else if(!st.empty() && st.top() < arr[i]) {
            nsl.push_back(st.top());
        }
        else if(!st.empty() && st.top() >= arr[i]) {
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nsl.push_back(-1);
            }
            else {
                nsl.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }

    // My Code
    // for (int i = 0; i < n; i++) {
    //     while(!st.empty() && st.top() >= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         nsl.push_back(-1);
    //     }
    //     else {
    //         nsl.push_back(st.top());
    //     }
    //     st.push(arr[i]);
    // }
    
    cout << "NSL Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << nsl[i] << " ";
    }
    cout << "]";
    return 0;
}