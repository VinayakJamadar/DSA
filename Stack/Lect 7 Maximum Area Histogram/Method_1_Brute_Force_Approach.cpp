// Problem: Maximum Area Histogram(MAH)
// Calculate the Maximum Area of Rectangle

// Method 1: Brute Force (i.e using 2 Nested 'for' loop) Approach

// Time Complexity: O(n^2)
// Reason: Using 2 Nested 'for' loop.

// Space Complexity: O(1)
// Reason: Not using any Data Structure

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