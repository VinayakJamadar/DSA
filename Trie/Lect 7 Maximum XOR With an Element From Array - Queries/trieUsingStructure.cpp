// Problem: Maximum XOR With an Element From Array - Queries
// Article Link: https://takeuforward.org/trie/maximum-xor-queries-trie/


// N = Number of elements in arr
// M = Number of elements in queries


// Time Complexity: O(N*32) + O(M*32)
// Reason: 
// 1. O(N*32) for inserting all the elements of arr1 into the trie take O(N*32) [32 Bit] 
// 2. O(M*32) for finding the maxXOR for every element of arr2.


// Space Complexity: O(N*32)
// Reason: Since we are inserting all the elements of arr1 into trie where every element is of size 32 bit but the space complexity will be less than O(N*32) because they might have overlapped.


#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node* links[2];

	//checks if the reference trie is present or not
	bool containKey(bool bit) {
		return (links[bit] != NULL);
	}
	
	//creating reference trie
	void put(bool bit, Node* node) {
		links[bit] = node;
	}
	
	//to get the next node for traversal
	Node* get(bool bit) {
		return links[bit];
	}
};

class Trie {
	private: 
		Node* root;

	public:
		Trie() {
			root = new Node();
		}

		void insert(int num) {
			Node* node = root;
			for (int i = 31; i >= 0; i--) {
				bool bit = (num >> i) & 1;
				if (!node->containKey(bit)) {
					node->put(bit, new Node());
				}
				node = node->get(bit);
			}
		}

		int findMax(int num) {
			Node* node = root;
			int maxNum = 0;
			for (int i = 31; i >= 0; i--) {
				bool bit = (num >> i) & 1;
				if (node->containKey(!bit)) {
					maxNum = maxNum | (1 << i);
					node = node->get(!bit);
				} 
				else {
					node = node->get(bit);
				}
			}
			return maxNum;
		}
};

vector<int> maxXorQueries(vector <int>& arr, vector<vector<int>>& queries) {
	sort(arr.begin(), arr.end());

	int index = 0;
	vector<pair<int, pair<int, int>>> offlineQueries;
	for(auto it: queries) {
		offlineQueries.push_back({it[1], {it[0], index++}});
	}

	sort(offlineQueries.begin(), offlineQueries.end());

	Trie trie;
	int n = arr.size();
	int i = 0;
	vector<int> ans(queries.size(), 0);

	for(auto it: offlineQueries) {
		while (i < n && arr[i] <= it.first) {
			trie.insert(arr[i]);
			i++;
		}
		if(i != 0) ans[it.second.second] = trie.findMax(it.second.first);
		else ans[it.second.second] = -1;
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

        vector<int> ans = maxXorQueries(arr, queries);
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