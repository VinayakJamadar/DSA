// Problem: Delete a Node in Binary Search Tree

// Approach: Attach Nodes Right Child to the Right Node of Left Subtree's Right Most Node

//               BST
//                8
//          /         \
//         5           12
//      /     \      /    \
//     2       7    10    13
//   /  \     /
//  1   3    6       
//       \
//        4

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

// Return the Right Most Node of a Tree
Node* findLastRight(Node* root) {
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Attach Nodes Right Child to the Right Node of Left Subtree's Right Most Node
Node* helper(Node* root) {
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(root->data == key) {
        return helper(root);
    }

    Node* dummy = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            }
            else {
                root = root->left;
            }
        }
        else {
            if(root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            }
            else {
                root = root->right;
            }
        }
    }
    
    return dummy;
}

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(13);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(6);
    root->left->left->right->right = new Node(4);

    int key = 5;
    
    vector<int> before;
    inOrder(root, before);
    cout << "Inorder Before Delete Node " << key << " : [ ";
    for (int i = 0; i < before.size(); i++)
    {
        cout<<before[i]<<" ";
    }
    cout<<"]"<<endl;

    root = deleteNode(root, key);

    vector<int> after;
    inOrder(root, after);
    cout << "Inorder After Delete Node " << key << " : [ ";
    for (int i = 0; i < after.size(); i++)
    {
        cout<<after[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}