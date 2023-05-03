// Problem : Minimum Window Substring

// Time Complexity : O(n*log(max(k, 26)))
// Reason : O(n) for traversing through 'while' loop and O(log(max(k, 26))) for searching and erase in map 'alphabetCnt'
// Space Complexity : O(max(k, 26))
// Reason : O(max(k, 26)) for map 'alphabetCnt'

// Important Note :

// 1. i is start of Window
// 2. j is end of Window
// 3. k is Given Condition (or Value)


// 6 Steps of Variable Size Sliding Window

// 1. Data Structures required for Problem
//      1.1. Declare DS1 -> Which stores the Final Answer 
//      1.2. Declare DS2 -> Which stores the possible candidate from current Window for Final Answer
// 2. Iterate till Last possible limit of Sliding Window
// 3. If Required do Some Calculations on jth element and store on DS2
// 4. If DS2 equal to k
//      4.1. Find the answer from DS1 and DS2 and store on DS1
//      4.2. Iterate till DS2 is equal to k
//          4.2.1. If Requried Remove Calculations done on ith element from DS2
//          4.2.2. Find the answer from DS1 and DS2 and store on DS1
//          4.2.3. Increment i (i.e Slide the Window)
// 5. Increment j (i.e Increment size of Window)
// 6. Displaying or Returning the DS1


#include<bits/stdc++.h>
using namespace std;

// This is Exception Case of Variable Size Sliding Window
// So it will not follow general format or template of Variable Size Sliding Window

int main(){
    string s = "TOTMTAPTAT", t = "TTA";
    int n = s.size();
    int i = 0, j = 0;
    // 1. Data Structrues required for Problem
    // 1.1. Declare DS1 -> Which stores the Final Answer
    int ans = INT_MAX;
    // 1.2. Declare DS2 -> Which stores the possible candidate from current Window for Final Answer
    map<char, int> alphabetCnt;
    for (int i = 0; i < t.size(); i++)
    {
        alphabetCnt[t[i]]++;
    }

    int k = alphabetCnt.size(), count = 0;
    // 2. Iterate till Last possible limit of Sliding Window
    while(j < n) {
        // 3. If Required do Some Calculations on jth element and store on DS2
        if(alphabetCnt.find(s[j]) != alphabetCnt.end()) {
            alphabetCnt[s[j]]--;
            if(alphabetCnt[s[j]] == 0) count++;
        }

        // 4. If DS2 equal to k
        if(count == k) {
            // 4.1. Find the answer from DS1 and DS2 and store on DS1
            ans = min(ans, j-i+1);

            // 4.2. Iterate till DS2 is equal to k
            while(count == k) {
                // 4.2.1. If Requried Remove Calculations done on ith element from DS2
                if(alphabetCnt.find(s[i]) != alphabetCnt.end()) {
                    alphabetCnt[s[i]]++;
                    if(alphabetCnt[s[i]] == 1) count--;
                }
                // 4.2.2. Find the answer from DS1 and DS2 and store on DS1
                ans = min(ans, j-i+1);
                // 4.2.3. Increment i (i.e Slide the Window)
                i++;
            }
        }
        // 5. Increment j (i.e Increment size of Window)
        j++;
    }
    // 6. Displaying or Returning the DS1
    cout<<"Minimum Window Substring is : "<<ans;
    return 0;
}