// Problem: Longest Word With All Prefixes - Complete String


// Time Complexity: O(n * len) + O(n * len) ~ O(n * len)
// Reason:
// 1. O(n * len) for inserting all the words in Trie Data Sturcture
// 2. O(n * len) to check word is Complete String or not

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch-'a']; 
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }

    void setEnd() {
        flag = true; 
    }

    bool isEnd() {
        return flag; 
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
            for(int i = 0; i < len; i++) {
                if(!node->containKey(word[i])) {
                    node->put(word[i], new Node()); 
                }
                node = node->get(word[i]); 
            }
            node->setEnd(); 
        }

        bool checkIfAllPrefixExists(string word) {
            Node* node = root;
            int len = word.size();
            for(int i = 0; i < len; i++) {
                if(node->containKey(word[i])) {
                    node = node->get(word[i]);
                    if(!node->isEnd()) return false;
                }
                else {
                    return false; 
                } 
            }
            return true; 
        }
};

string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();

    // Time Complexity: O(n * len)
    for(auto word : a) {
        obj->insert(word);
    }

    string longest = ""; 
    
    // Time Complexity: O(n * len)
    for(auto word: a) {
        if(obj->checkIfAllPrefixExists(word)) {
            if(word.size() > longest.size()) {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) {
                longest = word; 
            }
        }
    }

    if(longest == "") return "None"; 
    return longest; 
}

int main() {
	int n = 6;
	vector<string> a = {"n", "ninja", "ninj", "ni", "nin", "ninga"};

	string ans = completeString(n, a);
    // Complete String is: ninja
	cout << "Complete String is: " << ans << endl;
}