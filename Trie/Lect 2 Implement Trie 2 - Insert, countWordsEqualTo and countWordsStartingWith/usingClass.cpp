// Problem: Implement Trie 2 - Insert, countWordsEqualTo and countWordsStartingWith
// Article Link: https://takeuforward.org/data-structure/implement-trie-ii/


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
		int cntEndWith = 0;
		int cntPrefix = 0;

    public:
		bool containKey(char ch) {
			return (links[ch - 'a'] != NULL);
		}

		Node* get(char ch) {
			return links[ch - 'a'];
		}

		void put(char ch, Node * node) {
			links[ch - 'a'] = node;
		}

		void increaseEnd() {
			cntEndWith++;
		}

		void increasePrefix() {
			cntPrefix++;
		}

		void deleteEnd() {
			cntEndWith--;
		}

		void reducePrefix() {
			cntPrefix--;
		}

		int getEnd() {
			return cntEndWith;
		}

		int getPrefix() {
			return cntPrefix;
		}
};

class Trie {
	private:
		Node* root;

	public:
		/** Initialize your data structure here. */
		Trie() {
			root = new Node();
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			Node* node = root;
			int len = word.size();
			for (int i = 0; i < len; i++) {
				if (!node->containKey(word[i])) {
					node->put(word[i], new Node());
				}
				node = node->get(word[i]);
				node->increasePrefix();
			}
			node->increaseEnd();
		}

		int countWordsEqualTo(string& word) {
			Node* node = root;
			int len = word.size();
			for (int i = 0; i < len; i++) {
				if (node->containKey(word[i])) {
					node = node->get(word[i]);
				}
				else {
					return 0;
				}
			}
			return node->getEnd();
		}

		int countWordsStartingWith(string& word) {
			Node* node = root;
			int len = word.size();
			for (int i = 0; i < len; i++) {
				if (node->containKey(word[i])) {
					node = node->get(word[i]);
				} else {
					return 0;
				}
			}
			return node->getPrefix();
		}

		void erase(string& word) {
			Node* node = root;
			int len = word.size();
			for (int i = 0; i < len; i++) {
				if (node->containKey(word[i])) {
					node = node->get(word[i]);
					node->reducePrefix();
				} 
				else {
					return;
				}
			}
			node->deleteEnd();
		}
};

int main() {
	Trie T;
	T.insert("apple");
	T.insert("apple");
	T.insert("apps");
	T.insert("apps");
	string word1 = "apps";
	cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
	string word2 = "abc";
	cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
	string word3 = "ap";
	cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)<<endl;
	string word4 = "appl";
	cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)<<endl;
	T.erase(word1);
	cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
	return 0;
}

// Output:
// Count Words Equal to apps 2
// Count Words Equal to abc 0
// Count Words Starting With ap 4
// Count Words Starting With appl 2
// Count Words equal to apps 1