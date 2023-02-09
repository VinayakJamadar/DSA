// Problem : Allocate Minimum Number Of Pages

// Method 1 : Binary Search

// Time Complexity : O(n*log(n))

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int n, int k, int maxPages) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > maxPages) {
            students++;
            sum = arr[i];
            if(students > k) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> arr{10, 20, 30, 40};
    int n = arr.size(), k = 2, res = 0;
    if(n < k) res = -1;
    else {
        int maxInd = max_element(arr.begin(), arr.end()) - arr.begin();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        // Set low = max element of arr
        // Set high = sum of arr
        int low = arr[maxInd], high = sum;
        while(low <= high) {
            int mid = (low + high)/2;
            if(isValid(arr, n, k, mid)) {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}