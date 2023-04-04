// Problem: Lowest Common Ancestor in Binary Tree

// Method 2: Optimization Approach

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

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

// Modified Version of PreOrder Traversal 

Node* lca(Node* root, int x, int y) {
    if(root == NULL) return NULL;

    if(root->data == x || root->data == y) return root;
    Node* left = lca(root->left, x, y);
    Node* right = lca(root->right, x, y);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else if(left != NULL && right != NULL) return root;
    else return NULL;
}

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
    cout << "lca(" << x << ", "<< y << "): " << lca(root, x, y)->data << endl;
    return 0;
}