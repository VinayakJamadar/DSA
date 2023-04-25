// Problem: Construct a BST from a preorder traversal

// Approach1: bruteForce1 - Constructing a BST by Inserting all the Nodes

//     BST of Given Preorder
//               8
//          /       \
//         5         10
//      /    \         \
//     1     7          12

// Time Complexity: O(n^2)
// Reason: O(n) for Insert a Node in BST and We are inserting 'n' nodes.

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

// Approach: We will traverse and find a Leaf Node Position where we can insert given Node

Node* insertIntoBST(Node* root, int key) {
    if(root == NULL) return new Node(key);

    Node* cur = root;
    while(1) {
        if(cur->data <= key) {
            if(cur->right != NULL) {
                cur = cur->right;
            }
            else {
                cur->right = new Node(key);
                break;
            }
        }
        else {
            if(cur->left != NULL) {
                cur = cur->left;
            }
            else {
                cur->left = new Node(key);
                break;
            }
        }
    }

    return root;
}

void preOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

int main(){
    vector<int> preorder{8, 5, 1, 7, 10, 12};
    cout << "Given preorder is: [ ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout<<preorder[i]<<" ";
    }
    cout<<"]"<<endl;

    Node* root = NULL;
    for (int i = 0; i < preorder.size(); i++)
    {
        root = insertIntoBST(root, preorder[i]);
    }

    vector<int> after;
    preOrder(root, after);
    cout << "Preorder of Constructed BST is: [ ";
    for (int i = 0; i < after.size(); i++)
    {
        cout<<after[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}