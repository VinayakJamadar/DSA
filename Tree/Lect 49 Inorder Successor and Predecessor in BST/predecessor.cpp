// Problem: Inorder Predecessor in BST


//              BST
//               5
//          /        \
//         2          7
//      /    \      /   \
//     1     4     6     9
//          /           / \
//         3           8  10

// inorderPredecessor(8) = 7
// inorderPredecessor(3) = 2

// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Space

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

Node* inorderPredecessor(Node* root, int val) {
    Node* predecessor = NULL;

    while(root != NULL) {
        if(root->data >= val) {
            root = root->left;
        }
        else {
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    int val = 8;
    cout << "Inorder Predecessor of " << val << " is: " << inorderPredecessor(root, val)->data << endl;
    val = 3;
    cout << "Inorder Predecessor of " << val << " is: " << inorderPredecessor(root, val)->data << endl;
    return 0;
}