// Problem: NGR or Nearest Greater to right or Next Largest Element

// Method 2: Stack Approach

// Time Complexity: O(n)
// Reason: At worst case 'for' loop iterate 'n' times.

// Space Complexity: O(n)
// Reason: Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'n' elements of 'arr' array.

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 3, 0, 0, 1, 2, 4};

    int n = arr.size();
    
    vector<int> ngr;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = n-1; i >= 0; i--) {
        if(st.empty()) {
            ngr.push_back(-1);
        }
        else if(!st.empty() && st.top() > arr[i]) {
            ngr.push_back(st.top());
        }
        else if(!st.empty() && st.top() <= arr[i]) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ngr.push_back(-1);
            }
            else {
                ngr.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }

    // My Code
    // for (int i = n-1; i >= 0; i--) {
    //     while(!st.empty() && st.top() <= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         ngr.push_back(-1);
    //     }
    //     else {
    //         ngr.push_back(st.top());
    //     }
    //     st.push(arr[i]);
    // }
    
    reverse(ngr.begin(), ngr.end());

    cout << "NGR Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << ngr[i] << " ";
    }
    cout << "]";
    return 0;
}