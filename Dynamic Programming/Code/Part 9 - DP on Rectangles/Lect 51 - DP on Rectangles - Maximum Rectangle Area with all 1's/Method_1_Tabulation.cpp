// Topic : DP on Rectangles
// Problem : Maximum Rectangle Area with all 1's

// Method 1 : Using Tabulation (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*max(m, n))
// Reason : As we are using two nested For Loops (n and max(m, n) iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(m)
// Reason : Using of vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(m) (i.e O(m) = O(1)+O(m))

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& histo) {
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty()) width = i;
            else width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

int main() {
    vector<vector<int>> mat{
        {1, 0, 1, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}
    };
    int n = mat.size(), m = mat[0].size();
    // Rather than naming dp here we have named it heights
    vector<int> heights(m, 0);
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mat[i][j]) heights[j]++;
            else heights[j] = 0;
        }

        int area = largestRectangleArea(heights);
        maxArea = max(maxArea, area);
    }
    
    cout<<"Maximum Rectangle Area with all 1's is : "<<maxArea;
    return 0;
}