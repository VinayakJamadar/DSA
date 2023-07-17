// Problem: NGL or Nearest Greater to left or Previous Largest Element

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
    
    vector<int> ngl;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = 0; i < n; i++) {
        if(st.empty()) {
            ngl.push_back(-1);
        }
        else if(!st.empty() && st.top() > arr[i]) {
            ngl.push_back(st.top());
        }
        else if(!st.empty() && st.top() <= arr[i]) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ngl.push_back(-1);
            }
            else {
                ngl.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }

    // My Code
    // for (int i = 0; i < n; i++) {
    //     while(!st.empty() && st.top() <= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         ngl.push_back(-1);
    //     }
    //     else {
    //         ngl.push_back(st.top());
    //     }
    //     st.push(arr[i]);
    // }
    
    cout << "NGL Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << ngl[i] << " ";
    }
    cout << "]";
    return 0;
}