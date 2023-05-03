// Problem : Count Occurences of Anagrams

// Time Complexity : O(n*log(max(k, 26)))
// Reason : O(n) for traversing through 'while' loop and O(log(max(k, 26))) for searching and erase in map 'alphabetCnt'
// Space Complexity : O(max(k, 26))
// Reason : O(max(k, 26)) for map 'alphabetCnt'

// Important Note :

// 1. i is start of Window
// 2. j is end of Window
// 3. k is Given Window Size
// 4. Anagram : Rearranging letters in existing words to form new words.
// 5. No. of Anagrams of a String is : n! (were n is size of string)


// 6 Steps of Fixed Size Sliding Window

// 1. Data Structures required for Problem
//      1.1. Declare DS1 -> Which stores the Final Answer 
//      1.2. Declare DS2 -> Which stores the possible candidate from current Window for Final Answer
// 2. Iterate till Last possible limit of Sliding Window
// 3. If Required do Some Calculations on jth element and store on DS2
// 4. If Window size equal to k
//      4.1. Find the answer from DS1 and DS2 and store on DS1
//      4.2. If Requried Remove Calculations done on ith element from DS2
//      4.3. Increment i (i.e Slide the Window)
// 5. Increment j (i.e Increment size of Window)
// 6. Displaying or Returning the DS1

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "aabaabaa", ptr = "aaba";
    int n = str.size(), k = ptr.size();
    
    // 1. Data Structures required for Problem
    int i = 0, j = 0, sum = 0;
    // 1.1. Declare DS1 -> Which stores the Final Answer
    int ans = 0;
    // 1.2. Declare DS2 -> Which stores the possible candidate from current Window for Final Answer (here both alphabetCnt and count are DS2)
    map<char, int> alphabetCnt;
    for (int i = 0; i < k; i++)
    {
        alphabetCnt[ptr[i]]++;
    }

    int count = alphabetCnt.size();
    
    // 2. Iterate till Last possible limit of Sliding Window
    while(j < n) {
        // 3. If Required do Some Calculations on jth element and store on DS2
        if(alphabetCnt.find(str[j]) != alphabetCnt.end()) {
            alphabetCnt[str[j]]--;
            if(alphabetCnt[str[j]] == 0) count--;
        }

        // 4. If Window size equal to k
        if(j-i+1 == k) {
            // 4.1. Find the answer from DS1 and DS2 and store on DS1
            if(count == 0) {
                ans++;
            }
            // 4.2. If Requried Remove Calculations done on ith element from DS2
            if(alphabetCnt.find(str[i]) != alphabetCnt.end()) {
                alphabetCnt[str[i]]++;
                if(alphabetCnt[str[j]] == 1) count++;
            }
            // 4.3. Increment i (i.e Slide the Window)
            i++;
        }
        // 5. Increment j (i.e Increment size of Window)
        j++;
    }
    
    // 6. Displaying or Returning the DS1
    cout<<"Count Occurences of Anagrams of "<<ptr<<" in "<<str<<" is  : "<<ans;
    return 0;
}