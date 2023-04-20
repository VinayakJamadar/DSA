// Problem: Count total Nodes in a Complete Binary Tree

// Method 2: Optimization Approach (i.e Using Height of Complete Binary Tree)

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

// Time Complexity: O(log(n) * log(n))
// Reason: log(n)

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

int findHeightLeft(Node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->left; 
    }
    return hght; 
}

int findHeightRight(Node* cur) {
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->right; 
    }
    return hght; 
}

int countNodes(Node* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1; 
    
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    
    return 1 + leftNodes + rightNodes; 
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "The total number of nodes in the given complete binary tree are: " << countNodes(root) << endl;
    return 0;
}