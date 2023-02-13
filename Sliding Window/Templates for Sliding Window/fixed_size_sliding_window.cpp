// 6 Steps of Fixed Size Sliding Window

// 1. Data Structures required for Problem
//      1.1. Declare DS1 -> Which stores the Final Answer 
//      1.2. Declare DS2 -> Which stores the possible answer from Current Window
// 2. Iterate till Last possible limit of Sliding Window
// 3. If Required do Some Calculations on jth element and store on DS2
// 4. If Window size is less than k
//      4.1. Increment the Size of Window
// 5. If Window size equal to k
//      5.1. Find the answer from DS1 and DS2 and store on DS1
//      5.2. If Requried Remove Calculations done on ith element from DS2
//      5.3. Slide the Window
// 6. Displaying or Returning the DS1


// Just Complete Code A, B, C, D, E, F

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input for array
    vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7};
    int n = arr.size(), k = 3;

    // Input for string
    // string str = "aabaabaa"
    // int n = str.size(), k = 3;

    int i = 0, j = 0;

    // Code A. Step 1.1

    // Code B. Step 1.2

    while(j < n) {
        // Code C. Step 3

        if(j-i+1 < k) {
            j++;
        }
        else if(j-i+1 == k) {
            // Code D. Step 5.1

            // Code E. Step 5.2

            i++, j++;
        }
    }
    
    // Code F. Step 6
    return 0;
}