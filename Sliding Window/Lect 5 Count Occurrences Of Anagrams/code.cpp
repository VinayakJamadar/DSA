// Problem : Count Occurences of Anagrams

// Time Complexity : O(n)

// Important Note :

// 1. Anagram : Rearranging letters in existing words to form new words.
// 2. No. of Anagrams of a String is : n! (were n is size of string)

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "aabaabaa", ptr = "aaba";
    int n = str.size(), k = ptr.size();
    
    // 1. Data Structures required for Problem
    int i = 0, j = 0, sum = 0;
    // 1.1. Declare DS1 -> Which stores the Final Answer
    int ans = 0;
    // 1.2. Declare DS2 -> Which stores the possible answer from Current Window (here both alphabetCnt and count are DS2)
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
        // 4. If Window size is less than k
        if(j-i+1 < k) {
            // 4.1. Increment the Size of Window
            j++;
        }
        // 5. If Window size equal to k
        else if(j-i+1 == k) {
            // 5.1. Find the answer from DS1 and DS2 and store on DS1
            if(count == 0) {
                ans++;
            }
            // 5.2. If Requried Remove Calculations done on ith element from DS2
            if(alphabetCnt.find(str[i]) != alphabetCnt.end()) {
                alphabetCnt[str[i]]++;
                if(alphabetCnt[str[j]] == 1) count++;
            }
            // 5.3. Slide the Window
            i++, j++;
        }
    }
    
    // 6. Displaying or Returning the DS1
    cout<<"Count Occurences of Anagrams of "<<ptr<<" in "<<str<<" is  : "<<ans;
    return 0;
}