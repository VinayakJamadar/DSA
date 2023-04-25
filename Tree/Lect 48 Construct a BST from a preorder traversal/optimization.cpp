// Problem: Construct a BST from a preorder traversal

// Approach3: optimization - Constructing a BST by Using Property of BST and UpperBound(or maxVal)

// Note: Using Property of BST i.e For every node, Left Subtree must contain values less and Right Subtree must contain values greater than Current Node value.

//     BST of Given Preorder
//               8
//          /       \
//         5         10
//      /    \         \
//     1     7          12

// Time Complexity: O(3*n)
// Reason: We visit every node atleast 3 times

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

Node* build(vector<int>& preorder, int& i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    Node* root = new Node(preorder[i]);
    i++;
    root->left = build(preorder, i, root->data);
    root->right = build(preorder, i, bound);
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

    int i = 0;
    Node* root = build(preorder, i, INT_MAX);

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