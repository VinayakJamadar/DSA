// Problem: Insert a given Node in Binary Search Tree


//              BST
//               8
//          /       \
//         5         12
//      /    \     /    \
//     4     7    10    14
//          /          /
//         6         13

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
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);

    int key = 9;
    
    vector<int> before;
    inOrder(root, before);
    cout << "Inorder Before Insert Node " << key << " : [ ";
    for (int i = 0; i < before.size(); i++)
    {
        cout<<before[i]<<" ";
    }
    cout<<"]"<<endl;

    insertIntoBST(root, key);

    vector<int> after;
    inOrder(root, after);
    cout << "Inorder Before Insert Node " << key << " : [ ";
    for (int i = 0; i < after.size(); i++)
    {
        cout<<after[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}