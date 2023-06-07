// Problem: Word Ladder - II Optimised Approach for Leetcode
// Problem Link: https://leetcode.com/problems/word-ladder-ii/
// Article Link: https://takeuforward.org/graph/word-ladder-ii-optimised-approach-g-31/


// Time Complexity and Space Complexity: It cannot be predicted for this particular algorithm because there can be multiple sequences of transformation from startWord to targetWord depending upon the example, so we cannot define a fixed range of time or space in which this program would run for all the test cases.


// Approach: Optimized Single-source BFS


// Steps:
// 1. Finding the minimum number of steps to reach the endWord used in Word Ladder I Problem and storing the step number for every string in a data structure. So that we can backtrack at later stages.
// 2. Backtrack in the map from end to beginning using dfs to get the answer sequences.


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Create a map of type word->level to get the idea 
    // on which level the word comes after the transformations.
    unordered_map<string, int> mpp;

    // A vector for storing the final answer.
    vector<vector<string>> ans;
    string startWord;

private:
    void dfs(string word, vector<string> &seq) {
        // Function for implementing backtracking using the created map
        // in reverse order to find the transformation sequence in less time.

        // Base condition :
        // If word equals beginWord, we’ve found one of the sequences
        // simply reverse the sequence and return. 
        if (word == startWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
    
            // reverse again so that the dfs calls are not disturbed.
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];

        // Replace each character of the word with letters from a-z 
        // and check whether the transformed word is present in the map
        // and at the previous level or not.  
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    // pop the current word from the back of the queue
                    // to traverse other possibilities.
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Perform BFS traversal and push the string in the queue
        // as soon as they’re found in the wordList.
        queue<string> q;
        startWord = beginWord;
        q.push({beginWord});

        // beginWord initialised with level 1.
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty()) {

            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            // Break out if the word matches the endWord
            if (word == endWord)
                break;

            // Replace each character of the word with letters from a-z 
            // and check whether the transformed word is present in the 
            // wordList or not, if yes then push to queue
            for (int i = 0; i < sz; i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);

                        // push the word along with its level
                        // in the map data structure.
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
    
        // If we reach the endWord, we stop and move to step-2
        // that is to perform reverse dfs traversal.
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";

    Solution obj; 
    vector<vector<string>> ans = obj.findLadders(beginWord, endWord, wordList);
    
    // Output:
    // hit hot dot dog cog 
    // hit hot lot log cog
    for(auto i: ans) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
