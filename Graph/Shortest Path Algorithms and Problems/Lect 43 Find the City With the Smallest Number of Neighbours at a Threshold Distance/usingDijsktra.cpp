// Problem: Find the City With the Smallest Number of Neighbours at a Threshold Distance
// Article Link: https://takeuforward.org/data-structure/find-the-city-with-the-smallest-number-of-neighbours-at-a-threshold-distance-g-43/


// V = n = Number of Nodes
// E = m = Number of Edges


// Using Dijsktra's Alogrithm


// Time Complexity: O(V * (E * log(V))) or O(n * (m * log(n)))
// Reason: As dijsktra's alogrithm use O(E * log(V)) complexity. But we are using Dijsktra's Alogrithm for all 'V' or 'n' nodes. So, overall time complexity if O(V * (E * log(V))).


// Space Complexity: O(2E) + O(V) or O(2m) + O(n)
// Reason: O(2E) or O(2m) for storing graph in adjacency list and O(V) or O(n) for 'distTo' vector.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        int ans = 1e9, index = -1;

        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for(int k = 0; k < n; k++){
            queue<pair<int,int>> q;
            q.push({k, 0});

            vector<int>distTo(n, 1e9);
            distTo[k] = 0;
            
            while(!q.empty()){
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();

                for(auto it: adj[node]){
                    int adjNode = it.first;
                    int weight = it.second;

                    if(dist + weight < distTo[adjNode]){
                        distTo[adjNode] = dist + weight;
                        q.push({adjNode, distTo[adjNode]});
                    }
                }
            }

            int cnt = 0;
            for(auto it: distTo){
                if(it <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= ans){
                ans = cnt;
                index = max(index, k);
            }
        }
        
        return index;
    }
};


int main() {
	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);

	// Output: The answer is node: 3
	cout << "The answer is node: " << cityNo << endl;
	return 0;
}