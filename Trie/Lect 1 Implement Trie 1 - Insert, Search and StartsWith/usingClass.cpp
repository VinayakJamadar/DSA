// Problem: Implement Trie 1 - Insert, Search and StartsWith
// Article Link: https://takeuforward.org/data-structure/implement-trie-1/


// 1. insert()

// Time Complexity: O(len)
// Reason: using 'for' loop of 'len' iteration


// 2. search()

// Time Complexity: O(len)
// Reason: using 'for' loop of 'len' iteration


// 3. startsWith()

// Time Complexity: O(len)
// Reason: using 'for' loop of 'len' iteration


#include<bits/stdc++.h>
using namespace std;

class Node {
	private:
		Node* links[26];
		bool flag = false;

    public:
        //checks if the reference trie is present or not
        bool containKey(char ch) {
            return (links[ch - 'a'] != NULL);
        }
		
        //creating reference trie
        void put(char ch, Node *node) {
            links[ch - 'a'] = node;
        }
		
        //to get the next node for traversal
        Node* get(char ch) {
            return links[ch - 'a'];
        }
		
        //setting flag to true at the end of the word
        void setEnd() {
            flag = true;
        }
		
        //checking if the word is completed or not
        bool isEnd() {
            return flag;
        }
};

class Trie {
	private:
		Node* root;
	public:
		Trie() {
			//creating new obejct
			root = new Node();
		}

		void insert(string word) {
			//initializing dummy node pointing to root initially
			Node* node = root;
			for (int i = 0; i < word.size(); i++) {
				if (!node->containKey(word[i])) {
					node->put(word[i], new Node());
				}
				//moves to reference trie
				node = node->get(word[i]);
			}
			node->setEnd();
		}

		bool search(string word) {
			Node* node = root;
			for (int i = 0; i < word.size(); i++) {
				if (!node->containKey(word[i])) {
					return false;
				}
				node = node->get(word[i]);
			}
			return node->isEnd();
		}

		bool startsWith(string prefix) {
			Node* node = root;
			for (int i = 0; i < prefix.size(); i++) {
				if (!node->containKey(prefix[i])) {
					return false;
				}
				node = node->get(prefix[i]);
			}
			return true;
		}
};

int main() {
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}

// Output:
// true
// true
// false