// Problem: Number of Distinct Substrings in a String
// Article Link: https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/


// Time Complexity: O(n^2)
// Reason: because we have to go through the entire string for all possible different starting points (i.e using two nested 'for' loop of n iteration) in order to generate all the substrings.

// Space Complexity: O(n^2)
// Reason: because in the worst case, all the substrings can be distinct and there will be a trie node for each alphabet of every substring. Number of substrings of a string of length n is (n * (n + 1) / 2). Hence in the worst case, space complexity will be O(n^2).

#include<iostream>
using namespace std;

struct Node {
    Node* links[26]; 
    
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch-'a']; 
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
}; 

int countDistinctSubstrings(string& s) {
    Node* root = new Node();
    int count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        Node* node = root;
        for (int j = i; j < n; j++) {
            if (!node->containKey(s[j])) {
                node -> put(s[j], new Node());
                count++;
            }
            node = node -> get(s[j]);
        }
    }

    // Adding extra 1 for empty Substring
    return count + 1;
}

int main() {
    string s1 = "ababa";
    cout << "Total number of distinct substrings of \""<< s1 << "\": " << countDistinctSubstrings(s1);
    cout << "\n";

    string s2 = "ccfdf";
    cout << "Total number of distinct substrings of \""<< s2 << "\": " << countDistinctSubstrings(s2);

    return 0;
}

// Output:
// Total number of distinct substrings of "ababa": 10
// Total number of distinct substrings of "ccfdf": 14