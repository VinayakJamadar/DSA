// Problem: Maximum Area Histogram(MAH)
// Calculate the Maximum Area of Rectangle

// Method 2: Stack Approach

// Time Complexity: O(n)
// Reason: At worst case 'for' loop iterate 'n' times.

// Space Complexity: O(n)
// Reason: 
// O(n) for Using Data Structure Stack 'st'. Which at worst case (i.e If 'arr' array is Sorted) store all 'n' elements of 'arr' array.


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

int main(){
    vector<int> histogram{6, 2, 5, 4, 5, 1, 6};

    int n = histogram.size();
    int mah = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histogram[st.top()] >= histogram[i])) {
            int height = histogram[st.top()];
            st.pop();
            int width;
            if (st.empty()) width = i;
            else width = i - st.top() - 1;
            mah = max(mah, width * height);
        }
        st.push(i);
    }

    cout << "Maximum Area Histogram: " << mah;
    return 0;
}