// Important Note :

// 1. i is start of Window
// 2. j is end of Window
// 3. k is Given Window Size


// 6 Steps of Fixed Size Sliding Window

// 1. Data Structures required for Problem
//      1.1. Declare DS1 -> Which stores the Final Answer 
//      1.2. Declare DS2 -> Which stores the possible candidate for from current Window for Final Answer
// 2. Iterate till Last possible limit of Sliding Window
// 3. If Required do Some Calculations on jth element and store on DS2
// 4. If Window size equal to k
//      4.1. Find the answer from DS1 and DS2 and store on DS1
//      4.2. If Requried Remove Calculations done on ith element from DS2
//      4.3. Increment i (i.e Slide the Window)
// 5. Increment j (i.e Increment size of Window)
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

        if(j-i+1 == k) {
            // Code D. Step 5.1

            // Code E. Step 5.2

            i++;
        }
        j++;
    }
    
    // Code F. Step 6
    return 0;
}