// Problem: Max Area Rectangle in binary matrix

// Method 1: Brute Force (i.e using 2 Nested 'for' loop) Approach

// Time Complexity: O((n^2)*m)
// Reason: Calling 'calculateMAH' function for 'm' times and O(n^2) for Using 2 Nested 'for' loop in 'calculateMAH'

// Space Complexity: O(1)
// Reason: Not using any Data Structure

// Algorithm:
// Call 'calculateMAH' function for every row in matrix and return the maximum from all the rows.

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateNSLIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> nslIndex(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if(arr[j] < arr[i]) {
                nslIndex[i] = j;
                break;
            }
        }
    }

    return nslIndex;
}

vector<int> calculateNSRIndex(vector<int>& arr) {
    int n = arr.size();
    // And for not possible case rather than '-1' we keep 'n'
    vector<int> nsrIndex(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                nsrIndex[i] = j;
                break;
            }
        }
    }

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