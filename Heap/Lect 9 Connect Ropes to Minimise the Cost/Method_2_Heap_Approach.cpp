// Problem : Connect Ropes to Minimise the Cost

// Time Complexity : O(n*n*log(n))

// Reason : O(n) for 'while' loop and O(n*log(n)) for heap

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{1, 2, 3, 4, 5};
    int n = arr.size();

    // Solution
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    int totalCost = 0;
    while (minHeap.size() > 1)
    {
        int rope1 = minHeap.top();
        minHeap.pop();
        int rope2 = minHeap.top();
        minHeap.pop();
        
        int cost = rope1 + rope2;
        totalCost += cost;

        minHeap.push(cost);
    }
    
    cout<<"Minimium Cost to Connect Ropes is : "<<totalCost;
    return 0;
}