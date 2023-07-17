// Problem: Maximum Area Histogram(MAH)
// Calculate the Maximum Area of Rectangle

// Method 2: Stack Approach

// Time Complexity: O(n*m)
// Reason: 
// Reason: Calling 'calculateMAH' function for 'm' times and O(n) At worst case 'for' loop iterate 'n' times in 'calculateMAH'

// Space Complexity: O(m)
// Reason: Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'm' elements of 'height' array.

// Algorithm:
// Call 'calculateMAH' function for every row in matrix and return the maximum from all the rows.

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

int calculateMAH(vector<int>& height) {
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

    return mah;
}

int main(){
    vector<vector<int>> matrix{
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    vector<vector<int>> grid = matrix;

    int n = grid.size(), m = grid[0].size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i > 0 && grid[i][j]) {
                grid[i][j] = 1 + grid[i-1][j];
            }
        }
        cout << "\nAt row " << i << endl;
        ans = max(ans, calculateMAH(grid[i]));
        cout << endl;
    }
    
    cout << "\nMax Area Rectangle in binary matrix: " << ans << endl;
    return 0;
}