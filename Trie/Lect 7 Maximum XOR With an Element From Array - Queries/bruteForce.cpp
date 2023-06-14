// Problem: Maximum XOR With an Element From Array - Queries
// Article Link: https://takeuforward.org/trie/maximum-xor-queries-trie/


// N = Number of elements in arr
// M = Number of elements in queries


// Time Complexity: O(M * N)
// Reason: for every query, we are running a for loop on N elements and calculating XOR value. So for M queries, it will be (M * N).


// Space Complexity: O(1)
// Reason: not using data structure


#include<bits/stdc++.h>
using namespace std;

vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    int m = queries.size();
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= queries[i][1]) {
                ans[i] = max(ans[i], arr[j] ^ queries[i][0]);
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> queries;

        for (int i = 0; i < m; i++) {
            vector<int> temp;
            int xi, ai;
            cin >> xi >> ai;
            temp.push_back(xi);
            temp.push_back(ai);
            queries.push_back(temp);
        }

        vector <int> ans = maxXorQueries(arr, queries);
        cout << "Output: " ;
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
}

// Input:
// 2
// 5 2
// 0 1 2 3 4
// 1 3
// 5 6
// 1 1
// 1
// 1 0

// Output:
// 3 7
// -1