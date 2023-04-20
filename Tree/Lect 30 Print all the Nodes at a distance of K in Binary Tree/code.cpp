// Problem: Print all the Nodes at a distance of K in Binary Tree

//      Tree
//         3
//     /      \
//    5        1
//   / \      / \
//  6   2    0   8
//     / \
//    7   4

// Nodes at a Distance of K = 2 from Target = 5 : [7, 4, 1]

// Time Complexity: O(n)+O(n) = O(n)
// Reason: As we traverse all the node of tree using BFS Traversal in Both markParents and distanceK function.

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
// 3. Collect all the Nodes at Distance K from Target


// Similar to Tree BFS Traversal
void markParents(Node* root, unordered_map<Node*, Node*> &parent_track, Node* target) { 
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right) {
            parent_track [current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(Node* root, Node* target, int k) { 
    unordered_map<Node*, Node*> parent_track; // node -> parent
    markParents(root, parent_track, target);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    /* BFS to go upto K level from target node and using our hashtable info*/
    while(!q.empty()) { 
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = 1;
            }
            if(current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = 1;
            }
            if(parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = 1;
            }
        }
    }

    vector<int> result;
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);
    }

    return result;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node* target = root->left;
    int k = 2;

    vector<int> result = distanceK(root, target, k);
    
    cout << "Nodes at a Distance of K = " << k << " from Target = " << target->data << " : [ ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}