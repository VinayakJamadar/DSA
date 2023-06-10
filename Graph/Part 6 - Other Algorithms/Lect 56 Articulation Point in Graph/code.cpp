// Problem: Articulation Point in Graph
// Article Link: https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/


// Articulation Point: 
// Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components.


// Intuition

// Similiar to Bridges in Graph (Check Lect 55) and DFS with Time of Insertion and Lowest Time of Insertion

// Time of insertion(tin[]): 
// 1. Dring the DFS call, the time when a node is visited, is called its time of insertion. For example, if in the above graph, we start DFS from node 0 it will visit node 1 first then node 2, node 3, and so on. So, the time of insertion for node 0 will be 1, node 1 will be 2, node 2 will be 3 and it will continue like this. We will use a time array to store the insertion time for each node.
// 2. This definition remains the same as it was during the bridge problem.

// Lowest Time of Insertion(low[]): 
// 1. In this case, the current node refers to all its adjacent nodes except the parent and the visited nodes and takes the minimum lowest time of insertion into account. To store this entity for each node, we will use another 'low' array.
// 2. The difference in finding the lowest time of insertion in this problem is that in the bridgealgorithm, we only excluded the parent node but in this algorithm, we are excluding the visited nodes along with the parent node.


// The logical modification of the DFS algorithm is discussed below:

// To find out the bridges in the bridge problem, we checked inside the DFS, if there exists any alternative path from the adjacent node to the current node.
// But here we cannot do so as in this case, we are trying to remove the current node along with all the edges linked to it. For that reason, here we will check if there exists any path from the adjacent node to the previous node of the current node. In addition to that, we must ensure that the current node we are trying to remove must not be the starting node. 

// The check conditions for this case will change like the following:
// if(low[it] > tin[node])  converts to if(low[it] >= tin[node] && parent  != -1) 


// The logic for the starting node:

// If the node is a starting point we will check the number of children of the node. If the starting node has more than 1 child(The children must not be connected), it will definitely be one of the articulation points.

// To find the number of children, we will generally count the number of adjacent nodes. But there is a point to notice. In the following graph, the starting node 0 has two adjacent nodes, but it is not an articulation point.

//       0
//     /  \
//    1    2

// To avoid this edge case, we will increment the number of children only if the adjacent node is not previously visited(i.e. child++ will be inside the not visited if statement).


// We can get a single node as an articulation point multiple times:

// To avoid the storing of duplicate nodes, we will store the nodes in a hash array(i.e. mark array used in the code) instead of directly inserting them in a simple array.


// Approach: 

// The algorithm steps are as follows:

// 1. First, we need to create the adjacency list for the given graph from the edge information(If not already given). And we will declare a variable timer(either globally or we can carry it while calling DFS), that will keep track of the time of insertion for each node. The timer may be initialized to 0 or 1 accordingly.
// 2. Then we will perform DFS for each component. For each component, the starting node will carry -1 as its parent.
    // 2.i. Inside DFS, we will first mark the node visited and then store the time of insertion and the lowest time of insertion properly. We will declare a child variable to implement the logic for starting node.
    // 2.ii. Now, it’s time to visit the adjacent nodes.
        // 2.ii.a. If the adjacent node is the parent itself, we will just continue to the next node.
        // 2.ii.b. If the adjacent node is not visited, we will call DFS for the adjacent node with the current node as the parent.
            // After the DFS gets completed, we will compare the lowest time of insertion of the current node and the adjacent node and take the minimum.
            // Now, we will check if the lowest time of insertion of the adjacent node is greater or equal to the time of insertion of the current node and also ensure that the current node is not the starting node(checking parent not equal -1).
            // If the condition matches, then we will mark the current node in our hash array as one of our answers as it is one of the articulation points of the graph.
            // Then we will increment the child variable by 1.
        // 2.ii.c. If the adjacent node is visited, we will just compare the lowest time of insertion of the current node and the time of insertion of the adjacent node and take the minimum.
    // 2.iii. Finally, we will check if the child value is greater than 1 and if the current node is the starting node. If it is then we will keep the starting node marked in our hash array as the starting node is also an articulation point in this case
// 3. Finally, our 'ans' array will store all the Articulation Point.


// Note: 
// 1. We are not considering the parent and the visited nodes during calculating the lowest insertion time as they may be the articulation points of the graph which means they may be the nodes we intend to remove.


// V = Number of Vertices
// E = Number of Edges


// Time Complexity: O(V+2E)
// Reason: O(V + 2E) for DFS traversal.


// Space Complexity: O(4V)
// Reason: O(4V) is for the three arrays i.e. tin, low, vis and mark each of size V.


#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (parent != -1 && low[it] >= tin[node]) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];

        // To avoid the storing of duplicate nodes
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0) return { -1};
        return ans;
    }
};

int main() {
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {2, 4}, {2, 5}, {4, 6}, {5, 6}};

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);

    // Output: 0 2
    for (auto it : nodes) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}