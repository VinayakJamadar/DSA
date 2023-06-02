// Problem: Alien Dictionary


// Notes:
// 1. Topological Sort: Linear ordering of vertices such that if there is an edge between u and v, then u appears before v in the ordering.
// 2. Topological sort is only valid in Directed Acyclic Graph (DAG)
// 3. Kahn's Algorithm is modified multisource BFS having starting nodes with indegree == 0


// Time Complexity: O(V + E)
// Reason: Time complexity of topological sort using bfs traversal (i.e. Kahn's Algorithm) in directed graph


// Space Complexity: O(2V)
// Reason: Space taken 'indegree' vector and 'q' queue.


// Approach:
// 1. So, here we need to find out the correct ordering of the first 4 letters of the alphabet(i.e. ‘a’, ‘b’, ‘c’, ‘d’). 
// 2. If we consider the first 2 words and try to figure out why “baa” appears before “abcd”, we can clearly observe that they are differentiated by the first letter i.e. ‘b’ and ‘a’. 
// 3. That is why, we can conclude that in the alien dictionary, ‘b’ appears before ‘a’( i.e. ‘b’ is smaller than ‘a’). 
// 4. We can correspond this differentiating factor to a directed graph where b -> a.
/* 5.  Let’s understand why we need not check “baa” and “abca” (the 1st and the 3rd word) next:
Until now, we have figured out why “baa” appears before “abcd”. So, by convention, if “abcd” is appearing before “abca” and “baa” is appearing before “abcd”, “baa” will obviously appear before “abca”. */
// 6. That is why we will check the pair of “abcd” and “abca” next rather than checking “baa” with any other words and this flow will be continued for the rest of the words.

// Important Note: Points to remember that we need not check every pair of words rather we will just check the consecutive pair of words in the dictionary.


// Follow-up question for the interview:

// Ques. When is the ordering not possible?
// There are two such cases when ordering is not possible:

// 1. If every character matches and the largest word appears before the shortest word: For example, if “abcd” appears before “abc”, we can say the ordering is not possible.

// 2. If there exists a cyclic dependency between the characters: For example, in the dictionary: dict: {“abc”, “bat”, “ade”} there exists a cyclic dependency between ‘a’ and ‘b’ because the dictionary states ‘a’ < ‘b’ < ‘a’, which is not possible.


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	// works for multiple components
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
public:
	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i];
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
	}
};

int main() {
	int N = 5, K = 4;
	string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

    // output: b d a c
	for (auto ch : ans) {
		cout << ch << ' ';
    }
	cout << endl;

	return 0;
}