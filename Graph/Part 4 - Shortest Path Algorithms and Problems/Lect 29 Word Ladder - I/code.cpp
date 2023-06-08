// Problem: Word Ladder - I


// N = Number of Nodes or Size of wordList Array
// M = Word length of words present in the wordList.


// Time Complexity: O(N * M * 26)
// Reason: O(N) for 'while' loop to traverse all the O(M * 26) for inner 'for' loops
// Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.


// Space Complexity: O(N) + O(N) ~ O(N)
// Reason: O(N) for 'q' queue and O(N) for creating an unordered set and copying all values from wordList into it.


// Approach: Simple Single-source BFS


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
        // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
};

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj; 
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);

    // Output: 3
    cout << ans;
    cout << endl;
    return 0;
}