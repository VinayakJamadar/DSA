// Problem: Maximum Area Histogram(MAH)
// Calculate the Maximum Area of Rectangle

// Method 2: Stack Approach

// Time Complexity: O(n)
// Reason: At worst case 'for' loop iterate 'n' times.

// Space Complexity: O(n)
// Reason: Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'n' elements of 'arr' array.

// Algorithm:
// 1. Find NSL Index array (nslIndex)
// 2. Find NSR Index array (nsrIndex)
// 3. Then width[i] = nsrIndex[i] - nslIndex[i] - 1
// 4. Then area[i] = height[i] * width[i]
// 5. Then mah = maximum element of 'area' array

// Note:
// 1. In Lect 4 NSL, for 'nsl' array we kept 'Nearest Smaller Element to Left' in Stack
// But in this Lect, for 'nslIndex' we kept 'Index of Nearest Smaller Element to Left' in Stack

// 2. In Lect 5 NSR, for 'nsr' array we kept 'Nearest Smaller Element to Right' in Stack
// But in this Lect, for 'nsrIndex' we kept 'Index of Nearest Smaller Element to Right' in Stack
// And for not possible case rather than '-1' we keep 'n'

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateNSLIndex(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> nslIndex;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = 0; i < n; i++) {
        if(st.empty()) {
            nslIndex.push_back(-1);
        }
        else if(!st.empty() && arr[st.top()] < arr[i]) {
            nslIndex.push_back(st.top());
        }
        else if(!st.empty() && arr[st.top()] >= arr[i]) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nslIndex.push_back(-1);
            }
            else {
                nslIndex.push_back(st.top());
            }
        }
        st.push(i);
    }

    // My Code
    // for (int i = 0; i < n; i++) {
    //     while(!st.empty() && arr[st.top()] >= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         nslIndex.push_back(-1);
    //     }
    //     else {
    //         nslIndex.push_back(st.top());
    //     }
    //     st.push(i);
    // }

    return nslIndex;
}

vector<int> calculateNSRIndex(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> nsrIndex;
    stack<int> st;

    // Aditya Verma's Code
    for (int i = n-1; i >= 0; i--) {
        if(st.empty()) {
            nsrIndex.push_back(n);
        }
        else if(!st.empty() && arr[st.top()] < arr[i]) {
            nsrIndex.push_back(st.top());
        }
        else if(!st.empty() && arr[st.top()] >= arr[i]) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nsrIndex.push_back(n);
            }
            else {
                nsrIndex.push_back(st.top());
            }
        }
        st.push(i);
    }

    // My Code
    // for (int i = n-1; i >= 0; i--) {
    //     while(!st.empty() && arr[st.top()] >= arr[i]) {
    //         st.pop();
    //     }
    //     if(st.empty()) {
    //         nsrIndex.push_back(n);
    //     }
    //     else {
    //         nsrIndex.push_back(st.top());
    //     }
    //     st.push(i);
    // }

    reverse(nsrIndex.begin(), nsrIndex.end());
    return nsrIndex;
}

void printArray(vector<int>& arr, string name) {
    cout << name << " Array: [ ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> height{6, 2, 5, 4, 5, 1, 6};

    int n = height.size();
    
    vector<int> nsrIndex = calculateNSRIndex(height);
    vector<int> nslIndex = calculateNSLIndex(height);
    vector<int> width(n);
    vector<int> area(n);

    for (int i = 0; i < n; i++) {
        width[i] = nsrIndex[i] - nslIndex[i] - 1;
    }
    
    for (int i = 0; i < n; i++) {
        area[i] = height[i] * width[i];
    }

    int mah = area[max_element(area.begin(), area.end()) - area.begin()];

    printArray(height, "height");
    printArray(nsrIndex, "nsrIndex");
    printArray(nslIndex, "nslIndex");
    printArray(width, "width");
    printArray(area, "area");
    cout << "Maximum Area Histogram: " << mah;
    return 0;
}