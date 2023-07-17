// Problem: NGL or Nearest Greater to left or Previous Largest Element

// Method 1: Brute Force (i.e using 2 Nested 'for' loop) Approach

// Time Complexity: O(n^2)
// Reason: Using 2 Nested 'for' loop.

// Space Complexity: O(1)
// Reason: Not using any Data Structure

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{1, 3, 0, 0, 1, 2, 4};

    int n = arr.size();
    
    vector<int> ngl(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if(arr[j] > arr[i]) {
                ngl[i] = arr[j];
                break;
            }
        }
    }
    
    cout << "NGL Array: [ ";
    for (int i = 0; i < n; i++) {
        cout << ngl[i] << " ";
    }
    cout << "]";
    return 0;
}