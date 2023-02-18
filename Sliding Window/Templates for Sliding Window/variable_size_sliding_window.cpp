// Important Note :

// 1. i is start of Window
// 2. j is end of Window
// 3. k is Given Condition (or Value)


// 7 Steps of Variable Size Sliding Window

// 1. Data Structures required for Problem
//      1.1. Declare DS1 -> Which stores the Final Answer 
//      1.2. Declare DS2 -> Which stores the possible candidate for from current Window for Final Answer
// 2. Iterate till Last possible limit of Sliding Window
// 3. If Required do Some Calculations on jth element and store on DS2
// 4. If DS2 equal to k
//      4.1. Find the answer from DS1 and DS2 and store on DS1
// 5. If DS2 is greater than k
//      5.1. Iterate till DS2 is greater than k
//          5.1.1. If Requried Remove Calculations done on ith element from DS2
//          5.1.2. Increment i (i.e Slide the Window)
//      5.2. If DS2 equal to k
//          5.2.1. Find the answer from DS1 and DS2 and store on DS1
// 6. Increment j (i.e Increment size of Window)
// 7. Displaying or Returning the DS1


#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input for array
    vector<int> arr{4, 1, 1, 1, 2, 3, 5};
    int n = arr.size(), k = 5;

    // Input for string
    // string str = "aabaabaa"
    // int n = str.size(), k = 3;

    int i = 0, j = 0;

    // Code A. Step 1.1

    // Code B. Step 1.2

    while(j < n) {
        // Code C. Step 3

        if(DS2 == k) {
            // Code D. Step 4.1
        }
        else if(DS2 > k) {

            while(DS2 > k) {
                // Code E. Step 5.1.1
                i++;
            }
            if(DS2 == k){
                // Code F. Step 5.2.1
            }
        }
        j++;
    }    

    // Code F. Step 7
    return 0;
}