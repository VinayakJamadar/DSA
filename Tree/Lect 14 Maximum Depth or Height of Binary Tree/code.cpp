// Problem: Maximum Depth or Height of Binary Tree

//        Tree
//         1
//       /  \
//      2    3
//         /  \ 
//        4    6
//       /
//      5 

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h)
// Where h = height of tree

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

int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right= new Node(6);
    root->right->left->left = new Node(5);

    cout<<"Height of Binary Tree: "<<height(root);
    return 0;
}