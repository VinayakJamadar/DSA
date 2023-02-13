// Problem : First Negative Number in every Window of Size k

// Time Complexity : O(n)

// Important Note :

// 1. i is start of Window
// 2. j is end of Window
// 3. k is size of Window

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

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{12, -1, -7, 8, -15, 30, 16, 28};
    int n = arr.size(), k = 3;
    // 1. Data Structures required for Problem
    int i = 0, j = 0;
    // 1.1. Declare DS1 -> Which stores the Final Answer
    vector<int> ans;
    // 1.2. Declare DS2 -> Which stores the possible answer from Current Window
    list<int> l;
    // 2. Iterate till Last possible limit of Sliding Window
    while(j < n) {
        // 3. If Required do Some Calculations on jth element and store on DS2
        if(arr[j] < 0) {
            l.push_back(arr[j]);
        }
        // 4. If Window size is less than k
        if(j-i+1 < k) {
            // 4.1. Increment the Size of Window
            j++;
        }
        // 5. If Window size equal to k
        else if(j-i+1 == k) {
            // 5.1. Find the answer from DS1 and DS2 and store on DS1
            if(l.size() == 0) {
                ans.push_back(0);
            }
            else {
                ans.push_back(l.front());
                // 5.2. If Requried Remove Calculations done on ith element from DS2
                if(arr[i] == l.front()) l.pop_front();
            }
            // 5.3. Slide the Window
            i++, j++;
        }
    }
    
    // 6. Displaying or Returning the DS1
    cout<<"First Negative Number in every Window of Size k is : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}