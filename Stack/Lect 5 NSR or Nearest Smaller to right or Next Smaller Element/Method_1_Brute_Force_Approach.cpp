// Problem: NSR or Nearest Smaller to right or Next Smallest Element

// Method 1: Brute Force (i.e using 2 Nested 'for' loop) Approach

// Time Complexity: O(n^2)
// Reason: Using 2 Nested 'for' loop.

// Space Complexity: O(1)
// Reason: Not using any Data Structure

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{4, 5, 2, 10, 8};

    int n = arr.size();
    
    vector<int> nsr(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                nsr[i] = arr[j];
                break;
            }
        }
    }
    
    cout << "NSR Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << nsr[i] << " ";
    }
    cout << "]";
    return 0;
}