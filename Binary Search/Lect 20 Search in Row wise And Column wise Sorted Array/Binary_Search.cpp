// Problem : Search in Row wise And Column wise Sorted Array

// Time Complexity : O(n+m)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr{
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int n = arr.size(), m = arr[0].size();
    int row = 0, col = m-1, key = 29;
    pair<int, int> ind{-1, -1};
    while(row <= n-1 and col >= 0) {
        if(arr[row][col] == key) {
            ind = {row, col};
            break;
        }
        else if(arr[row][col] > key) col--;
        else row++;
    }
    
    if(ind.first == -1 and ind.second == -1) cout<<"Key "<<key<<" not present in array";
    else cout<<"Key "<<key<<" is present at index : ("<<row<<","<<col<<")";
    return 0;
}