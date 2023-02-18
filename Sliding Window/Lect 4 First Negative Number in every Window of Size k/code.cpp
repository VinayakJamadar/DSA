// Problem : First Negative Number in every Window of Size k

// Time Complexity : O(n)
// Space Complexity : O(n+k) --> O(n) for vector 'ans' and O(k) for list 'l'

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

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{12, -1, -7, 8, -15, 30, 16, 28};
    int n = arr.size(), k = 3;
    // 1. Data Structures required for Problem
    int i = 0, j = 0;
    // 1.1. Declare DS1 -> Which stores the Final Answer
    vector<int> ans;
    // 1.2. Declare DS2 -> Which stores the possible candidate for from current Window for Final Answer
    list<int> l;
    // 2. Iterate till Last possible limit of Sliding Window
    while(j < n) {
        // 3. If Required do Some Calculations on jth element and store on DS2
        if(arr[j] < 0) {
            l.push_back(arr[j]);
        }
        
        // 4. If Window size equal to k
        if(j-i+1 == k) {
            if(l.size() == 0) {
                // 4.1. Find the answer from DS1 and DS2 and store on DS1
                ans.push_back(0);
            }
            else {
                // 4.1. Find the answer from DS1 and DS2 and store on DS1
                ans.push_back(l.front());
                // 4.2. If Requried Remove Calculations done on ith element from DS2
                if(arr[i] == l.front()) l.pop_front();
            }
            // 4.3. Increment i (i.e Slide the Window)
            i++;
        }
        // 5. Increment j (i.e Increment size of Window)
        j++;
    }
    
    // 6. Displaying or Returning the DS1
    cout<<"First Negative Number in every Window of Size k is : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}