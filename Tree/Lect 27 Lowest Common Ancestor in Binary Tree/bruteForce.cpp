// Problem: Lowest Common Ancestor in Binary Tree

// Method 1: Brute Force Approach 
// (i.e By Finding the path of Both Nodes and then lca is last common node in the both the path)

// Definition of Lowest Common Ancestor(LCA):
// The Ancestor that exist at Deepest Level

// Note:
// A Node can be a Ancestor of itself.
// So, LCA(x, y) can be either x, y or Ancestor exist at Deepest Level


//      Tree
//         1
//     /      \
//    2        3
//   / \      / \
//  4   5    8   9
//     / \
//    6   7

// LCA(4, 7) = 2
// LCA(5, 9) = 1
// LCA(2, 6) = 2

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h) + O(2k)
// Reason: 
// O(h) for Auxiliary Stack space taken by Recursion, Where h = height of tree
// O(2k) for storing root to node Path of both Nodes

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

// Striver's Approach

bool getPath(Node* root, int x, vector<int> &path) {
    if(root == NULL) return 0;

    path.push_back(root->data);

    if(root->data == x) return 1;

    if(getPath(root->left, x, path) || getPath(root->right, x, path)) {
        return 1;
    }

    path.pop_back();
    return 0;
}

// My Approach

// bool getPath(Node* root, int x, vector<int> &path) {
//     if(root == NULL) return 0;

//     if(root->data == x) {
//         path.push_back(root->data);
//         return 1;
//     }
//     bool left = getPath(root->left, x, path);
//     bool right = getPath(root->right, x, path);

//     if(left || right) {
//         path.push_back(root->data);
//         return 1;
//     }
//     return 0;
// }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    int x = 4, y = 7;
    vector<int> path1, path2;
    getPath(root, x, path1);
    // Uncomment below line if using My Approach
    // reverse(path1.begin(), path1.end());
    getPath(root, y, path2);
    // Uncomment below line if using My Approach
    // reverse(path2.begin(), path2.end());
    int lca;
    for (int i = 0; i < min(path1.size(), path2.size()); i++)
    {
        if(path1[i] == path2[i]) lca = path1[i];
        else break;
    }
    cout << "lca(" << x << ", "<< y << "): " << lca << endl;
    return 0;
}