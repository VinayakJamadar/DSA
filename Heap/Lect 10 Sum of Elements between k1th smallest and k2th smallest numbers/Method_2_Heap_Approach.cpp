// Problem : Sum of Elements between k1th smallest and k2th smallest numbers

// Time Complexity : O(n*log(max(k1, k2)))

#include<bits/stdc++.h>
using namespace std;

int kthSmallestElement(vector<int>& arr, int n, int k) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main(){
    // Input
    vector<int> arr{1, 3, 12, 5, 15, 11};
    int n = arr.size(), k1 = 3, k2 = 6;

    // Solution
    int first = kthSmallestElement(arr, n, k1);
    int second = kthSmallestElement(arr, n, k2);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > first and arr[i] < second) {
            sum += arr[i];
        }
    }
    
    cout<<"Sum of Elements between k1th smallest and k2th smallest numbers is : "<< sum;
    return 0;
}