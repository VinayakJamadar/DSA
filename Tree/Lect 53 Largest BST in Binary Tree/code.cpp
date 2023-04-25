// Problem: Largest BST in Binary Tree

//               BT
//               20
//          /         \
//         15          40
//     /      \      /    \
//   14       18    30    60
//     \     /  \        /
//     17  16   19     50

// Trick to Remember Postorder: Left Right Root
// Postorder: [17, 14, 16, 19, 18, 15, 30, 50, 60, 40, 20]

// Largest BST in Given BT is: 4
//             40
//           /   \
//         30    60
//              /
//            50

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(h), where h = height of tree
// Reason: Space taken by auxiliary stack which store at most nodes equal to height of tree.

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

class NodeValue {
    public:
        int maxSize, minNode, maxNode;

        NodeValue(int maxSize, int minNode, int maxNode) {
            this->maxSize = maxSize;
            this->minNode = minNode;
            this->maxNode = maxNode;
        }
};


// Similar to Postorder Traversal

NodeValue largestBSTSubtreeHelper(Node* root) {
    // An empty tree is a BST of size 0.
    if(root == NULL) {
        return NodeValue(0, INT_MAX, INT_MIN);
    }

    // Get values from left and right subtree of current tree.
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // Current node is greater than max in left and Smaller than min in right, then it is a BST
    if(left.maxNode < root->data && root->data < right.minNode) {
        // It is a BST.
        return NodeValue(1 + left.maxSize + right.maxSize, min(root->data, left.minNode), max(root->data, right.maxNode));
    }

    // Otherwise, return [maxSize, minNode, maxNode] = [max(left.maxSize, right.maxSize), INT_MIN, INT_MAX] so that parent can't be a valid BST
    return NodeValue(max(left.maxSize, right.maxSize), INT_MIN, INT_MAX);
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(40);
    root->left->left = new Node(14);
    root->left->right = new Node(18);
    root->right->left = new Node(30);
    root->right->right = new Node(60);
    root->left->left->right = new Node(17);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(19);
    root->right->right->left = new Node(50);

    cout << "Size of Largest BST in given BT is: " << largestBSTSubtreeHelper(root).maxSize << endl;
    return 0;
}