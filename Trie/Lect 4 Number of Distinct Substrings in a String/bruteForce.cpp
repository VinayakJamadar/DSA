// Problem: Number of Distinct Substrings in a String
// Article Link: https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/


// Time Complexity: O(n^2 * log(n))
// Reason: 
// 1. O(n^2) to go through the entire string for all possible different starting points (i.e using two nested 'for' loop of n iteration) in order to generate all the substrings.
// 2. O(log(n)) for searching in 'st' set

// Space Complexity: O(n^3)
// Reason: 
// 1. O(n^2) because in the worst case, all the substrings can be distinct and there will be a trie node for each alphabet of every substring. Number of substrings of a string of length n is (n * (n + 1) / 2). Hence in the worst case, space complexity will be O(n^2).
// 2. O(n) for storing every substring of average length is n.

#include<bits/stdc++.h>
using namespace std;

int countDistinctSubstrings(string& s) {
    int n = s.size();
    set<string> st;

    for (int i = 0; i < n; i++) {
        string t = "";
        for (int j = i; j < n; j++) {
            t += s[j];
            st.insert(t);
        }
    }

    // Adding extra 1 for empty Substring
    return st.size() + 1;
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