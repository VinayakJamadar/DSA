// Problem: Count total Nodes in a Complete Binary Tree

// Method 1: Brute Force Approach (i.e Using Inorder Traversal)

// Definition of Complete Binary Tree
// 1. All levels except the last one are completely filled
// 2. Last level nodes are as left as possible.

//            Tree
//              1
//          /     \
//         2       3
//       /  \     / 
//      4    5   6

// Total Nodes in a Complete Binary Tree: 6

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(log(n)) or O(h)
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

void inOrder(Node* root, int& count) {
    if (root == NULL) return;

    count++;
    inOrder(root->left, count);
    inOrder(root->right, count);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int count = 0;
    inOrder(root, count);

    cout << "The total number of nodes in the given complete binary tree are: " << count << endl;
    return 0;
}