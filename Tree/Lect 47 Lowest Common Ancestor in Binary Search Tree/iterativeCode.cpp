// Problem: LCA in Binary Search Tree using Iterative Approach

//          Tree
//           6
//       /      \
//      2        8
//    /  \     /  \ 
//   0    4   7   9
//       / \
//      3   5

// LCA(0, 5) = 2
// LCA(2, 5) = 2

// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Data Structure

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

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* lca(Node* root, int x, int y) {
    Node* cur = root;
    while(cur != NULL) {
        if(cur->data < x && cur->data < y) cur = cur->right;
        else if(cur->data > x && cur->data > y) cur = cur->left;
        else break;
    }
    return cur;
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    int x = 0, y = 5;
    cout << "lca(" << x << ", "<< y << "): " << lca(root, x, y)->data << endl;
    return 0;
}