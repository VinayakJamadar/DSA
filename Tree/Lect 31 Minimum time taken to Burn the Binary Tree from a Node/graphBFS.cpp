// Problem: Minimum time taken to Burn the Binary Tree from a Node

// Method 1: Graph BFS Approach

//      Tree
//        1
//     /    \
//    2      3
//   /      / \
//  4      5   6
//   \
//    7

// Minimum time taken to Burn the Binary Tree from Target Node 2 is: 3

// Time Complexity: O(n)+O(n) = O(n)
// Reason: As we traverse all the node of tree using BFS or DFS.

// Space Complexity: O(n)+O(n)+O(n) = O(n)
// O(n) for unordered_map 'parent_track', O(n) for unordered_map 'visited' and O(n) for queue 'q'

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node() {
            data = 0;
            left = NULL;
            right = NULL;
        }

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

// Steps
// 1. Parents Pointing (i.e Point Node with its Parent)
// 2. Perform Graph BFS traversal.
// 3. Return Depth of Graph from Target Node


// Similar to Tree BFS Traversal
void markParents (Node* root, unordered_map<Node*, Node*> &parent_track, Node* target) { 
    queue<Node*> queue;
    queue.push(root);
    while(!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        if(current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if(current->right) {
            parent_track [current->right] = current;
            queue.push(current->right);
        }
    }
}


// Using Graph BFS Traversal for Calculate Maximum Depth
int findMaxDistanceUsingBFS(Node* root, Node* target) { 
    unordered_map<Node*, Node*> parent_track; // node -> parent
    markParents(root, parent_track, target);

    unordered_map<Node*, bool> visited;
    queue<Node*> queue;
    queue.push(target);
    visited[target] = true;
    int ans = -1;
    while(!queue.empty()) {
        int size = queue.size();
        ans++;
        for(int i = 0; i < size; i++) {
            Node* current = queue.front();
            queue.pop();
            if(current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = 1;
            }
            if(current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = 1;
            }
            if(parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = 1;
            }
        }
    }

    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);

    Node* target = root->left;

    cout << "Minimum time taken to Burn the Binary Tree from a Target Node " << target->data << " is: " << findMaxDistanceUsingBFS(root, target) << endl;
    return 0;
}