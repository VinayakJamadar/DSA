// Problem : Pick Toys

// Time Complexity : O(n*log(max(k, 26)))
// Reason : O(n) for traversing through 'while' loop and O(log(max(k, 26))) for searching and erase in map 'alphabetCnt'
// Space Complexity : O(max(k, 26))
// Reason : O(max(k, 26)) for map 'alphabetCnt'

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
    string str = "abaccab";
    int n = str.size(), k = 2;
    int i = 0, j = 0;
    // 1. Data Structrues required for Problem
    // 1.1. Declare DS1 -> Which stores the Final Answer
    int ans = 0;
    // 1.2. Declare DS2 -> Which stores the possible candidate for from current Window for Final Answer
    map<char, int> alphabetCnt;
    // 2. Iterate till Last possible limit of Sliding Window
    while(j < n) {
        // 3. If Required do Some Calculations on jth element and store on DS2
        alphabetCnt[str[j]]++;

        // 4. If DS2 equal to k
        if(alphabetCnt.size() == k) {
            // 4.1. Find the answer from DS1 and DS2 and store on DS1
            ans = max(ans, j-i+1);
        }
        // 5. If DS2 is greater than k
        else if(alphabetCnt.size() > k) {
            // 5.1. Iterate till DS2 is greater than k
            while(alphabetCnt.size() > k) {
                // 5.1.1. If Requried Remove Calculations done on ith element from DS2
                alphabetCnt[str[i]]--;
                if(alphabetCnt[str[i]] == 0) {
                    alphabetCnt.erase(str[i]);
                }
                // 5.1.2. Increment i (i.e Slide the Window)
                i++;
            }
            // 5.2. If DS2 equal to k
            if(alphabetCnt.size() == k){
                // 5.2.1. Find the answer from DS1 and DS2 and store on DS1
                ans = max(ans, j-i+1);
            }
        }
        // 6. Increment j (i.e Increment size of Window)
        j++;
    }
    // 7. Displaying or Returning the DS1
    cout<<"Maximum Picked Toys are : "<<ans;
    return 0;
}