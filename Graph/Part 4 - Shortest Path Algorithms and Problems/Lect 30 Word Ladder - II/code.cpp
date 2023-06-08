// Problem: Word Ladder - II


// Time Complexity and Space Complexity: It cannot be predicted for this particular algorithm because there can be multiple sequences of transformation from startWord to targetWord depending upon the example, so we cannot define a fixed range of time or space in which this program would run for all the test cases.


// Approach: Optimized Single-source BFS


// 1. My Code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Creating a queue ds which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        // BFS traversal with pushing the new formed sequence in queue 
        // when after a transformation, a word is found in wordList.
        q.push({beginWord});

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        // A vector to store the resultant transformation sequence.
        vector<vector<string>> ans;

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<string> vec = q.front();
                q.pop();

                string word = vec.back();

                // store the answers if the end word matches with targetWord.
                if(word == endWord) {
                    // the first sequence where we reached end
                    if(ans.size() == 0) {
                        ans.push_back(vec);
                    }
                    else if(ans[0].size() == vec.size()) {
                        ans.push_back(vec);
                    }
                }
                for (int i = 0; i < word.size(); i++) {
                    // Now, replace each character of ‘word’ with char
                    // from a-z then check if ‘word’ exists in wordList.
                    char original = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        // Check if the word is present in the set 'st'
                        if(st.find(word) != st.end()) {
                            // Push the word along with the new sequence in the queue.
                            vec.push_back(word);
                            // mark as visited on the level
                            usedOnLevel.push_back(word);
                            q.push(vec);
                            vec.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }

            // Now, erase all words that have been
            // used in this level to transform
            for (auto i : usedOnLevel) {
                st.erase(i);
            }
            usedOnLevel.clear();
        }

        return ans;
    }
};

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string beginWord = "der", endWord = "dfs";

    Solution obj; 
    vector<vector<string>> ans = obj.findSequences(beginWord, endWord, wordList);
    
    // Output:
    // der dfr dfs
    // der des dfs
    for(auto i: ans) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}


// 2. Striver's Code
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
//         // Push all values of wordList into a set
//         // to make deletion from it easier and in less time complexity.
//         unordered_set<string> st(wordList.begin(), wordList.end());
        
//         // Creating a queue ds which stores the words in a sequence which is
//         // required to reach the targetWord after successive transformations.
//         queue<vector<string>> q;

//         // BFS traversal with pushing the new formed sequence in queue 
//         // when after a transformation, a word is found in wordList.
//         q.push({beginWord});

//         // A vector defined to store the words being currently used
//         // on a level during BFS.
//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);
//         int level = 0;

//         // A vector to store the resultant transformation sequence.
//         vector<vector<string>> ans;

//         while (!q.empty()) {
//             vector<string> vec = q.front();
//             q.pop();

//             // Now, erase all words that have been
//             // used in the previous levels to transform
//             if (vec.size() > level) {
//                 level++;
//                 for (auto it : usedOnLevel) {
//                     st.erase(it);
//                 }
//             }

//             string word = vec.back();

//             // store the answers if the end word matches with targetWord.
//             if (word == endWord) {
//                 // the first sequence where we reached end
//                 if (ans.size() == 0) {
//                     ans.push_back(vec);
//                 }
//                 else if (ans[0].size() == vec.size()) {
//                     ans.push_back(vec);
//                 }
//             }
//             for (int i = 0; i < word.size(); i++) {   
//                 // Now, replace each character of ‘word’ with char
//                 // from a-z then check if ‘word’ exists in wordList.
//                 char original = word[i];
//                 for (char c = 'a'; c <= 'z'; c++) {
//                     word[i] = c;
//                     if (st.count(word) > 0) { 
//                         // Check if the word is present in the wordList and
//                         // push the word along with the new sequence in the queue.
//                         vec.push_back(word);
//                         q.push(vec);
//                         // mark as visited on the level
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
//     string beginWord = "der", endWord = "dfs";

//     Solution obj; 
//     vector<vector<string>> ans = obj.findSequences(beginWord, endWord, wordList);
    
//     // Output:
//     // der dfr dfs
//     // der des dfs
//     for(auto i: ans) {
//         for(auto j: i) {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }