// Problem : k Largest Elements in array

// Time Complexity : O(n*n*log(n))

// Reason : O(n) for 'while' loop and O(n*log(n)) for sort() function

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input
    vector<int> arr{1, 2, 3, 4, 5};
    int n = arr.size();

    // Solution
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    int totalCost = 0;
    while (arr.size() > 1)
    {
        int rope1 = arr.back();
        arr.pop_back();
        int rope2 = arr.back();
        arr.pop_back();
        
        int cost = rope1 + rope2;
        totalCost += cost;

        arr.push_back(cost);
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
    }
    
    cout<<"Minimium Cost to Connect Ropes is : "<<totalCost;
    return 0;
}