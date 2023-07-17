// Problem: NSL or Nearest Smaller to left or Previous Smallest Element

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
    
    vector<int> nsl(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if(arr[j] < arr[i]) {
                nsl[i] = arr[j];
                break;
            }
        }
    }
    
    cout << "NSL Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << nsl[i] << " ";
    }
    cout << "]";
    return 0;
}