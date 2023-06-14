// Problem: Maximum XOR of Two Numbers in an Array
// Article Link: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/


// N = Number of elements in arr1
// M = Number of elements in arr2


// Time Complexity: O(N*32) + O(M*32)
// Reason: 
// 1. O(N*32) for inserting all the elements of arr1 into the trie take O(N*32) [32 Bit] 
// 2. O(M*32) for finding the maxXOR for every element of arr2.


// Space Complexity: O(N*32)
// Reason: Since we are inserting all the elements of arr1 into trie where every element is of size 32 bit but the space complexity will be less than O(N*32) because they might have overlapped.


#include<bits/stdc++.h>
using namespace std;

class Node {
	private:
		Node* links[2];

    public:
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

int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
	Trie trie;
	for (int i = 0; i < n; i++) {
		trie.insert(arr1[i]);
	}
	int maxi = 0;
	for (int i = 0; i < m; i++) {
		maxi = max(maxi, trie.findMax(arr2[i]));
	}
	return maxi;
}

int main() {
	vector <int> arr1 = {9, 8, 7, 5, 4};
	vector <int> arr2 = {7, 8, 2};
	int n = 5, m = 3;
	// Output: 15
	cout << maxXOR(n, m, arr1, arr2) << endl;
	return 0;
}