// Problem: Accounts Merge - DSU
// Article Link: https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/


// V = Number of Vertices
// E = Number of Edges


// Time Complexity: O(V + E) + O(E * 4a) + O(V * (ElogE + E))
// Reason: 
// 1. O(V + E) for visiting all the emails. 
// 2. O(E * 4a) for merging the accounts. 
// 3. O(V * (ElogE + E)) for sorting the emails and storing them in the answer array.


// Space Complexity: O(V) + O(V) + O(2V) ~ O(V)
// Reason:
// 1. O(V) + O(V) for the 'mergedMail' and the 'ans' array. 
// 2. O(2V) for the parent and size array used inside the Disjoint set data structure.


#include <bits/stdc++.h>
using namespace std;

//User function Template for C++
class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {

    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    // Output:
    // John: j1@com j2@com j3@com j5@com
    // John: j4@com
    // Mary: m1@com
    // Raj: r1@com r2@com r3@com
    for (auto acc : ans) {
        cout << acc[0] << ": ";
        int size = acc.size();
        for (int i = 1; i < size; i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}