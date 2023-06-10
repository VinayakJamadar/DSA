// Problem: Strongly Connected Components - Kosaraju's Algorithm
// Article Link: https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/


// Print Strong Connected Components


// Questions for Interviews

// Question 1: Find the number of strongly connected components of a given graph.
// Question 2: Print the strongly connected components of a given graph.


// Strong Connected Components

// 1. Strongly connected components(SCC) are only valid for directed graphs.

// 2. A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) inside that component, 'u is reachable from v' and 'v is reachable from u'.

// 3. A component containing a single vertex is always a strongly connected component.


// Algorithm: 

// The algorithm steps are as follows:

// Step 1: Sort all the nodes according to their finishing time:
// Explanation 1: To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.

// Step 2: Reverse all the edges of the entire graph:
// Explanation 2: Now, we will create another adjacency list and store the information of the graph in a reversed manner.

// Step 3: Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
// Explanation 3: Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.

// Step 4: Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.


// Note: 

// 1. The first step is to know, from which node we should start the DFS call.

// 2. The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.

// 3. The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.

// 4. The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.


// V = Number of Vertices
// E = Number of Edges


// Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E)
// Reason: 
// 1. O(V+E) for simple DFS
// 2. O(V+E) for reversing the graph
// 3. O(V+E) for DFS (dfs2) again to calculate SCC


// Space Complexity: O(V)+O(V)+O(V+E) ~ O(V+E)
// Reason:
// 1. O(V) for the visited array
// 2. O(V) for stack
// 3. O(V+E) space for storing the reversed adjacent list(adjR).


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs1(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs1(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<int> &vis, vector<int> adjR[], vector<int>& arr) {
        vis[node] = 1;
        arr.push_back(node);
        for (auto it : adjR[node]) {
            if (!vis[it]) {
                dfs2(it, vis, adjR, arr);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    void kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, vis, adj, st);
            }
        }

        // Step 2
        vector<int> adjR[V];
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjR[it].push_back(i);
            }
        }
        
        // Step 3
        vis.assign(V, 0);
        vector<vector<int>> scc;
        int noScc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                noScc++;
                vector<int> arr; 
                dfs2(node, vis, adjR, arr);
                scc.push_back(arr);
            }
        }

        // Output: 
        // The number of strongly connected components is: 4
        // scc[1] = 0 2 1
        // scc[2] = 3
        // scc[3] = 4 6 5
        // scc[4] = 7
        cout << "The number of strongly connected components is: " << noScc << endl;
        for (int i = 0; i < scc.size(); i++) {
            cout << "scc[" << i+1 << "] = ";
            for(auto j: scc[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 8;
    int edges[10][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {4, 7}, {5, 6}, {6, 4}, {6 ,7}};

    vector<int> adj[n];
    for(auto it: edges) {
        adj[it[0]].push_back(it[1]);
    }

    Solution obj;
    obj.kosaraju(n, adj);
    return 0;
}