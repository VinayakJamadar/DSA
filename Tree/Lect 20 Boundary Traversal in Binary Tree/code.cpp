// Problem: Zig-Zag or Spiral Traversal in Binary Tree


//        Tree
//          1
//       /    \
//      2      7
//     /        \ 
//    3          8
//     \        /
//     4       9
//    / \    /  \
//   5  6   10  11

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(n)
// Reason: At worst case if all the node are at same level queue store all the n nodes.

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

bool isLeaf(Node* node) {
    return (node->left == NULL and node->right == NULL);
}

void addLeftBoundary(Node* root, vector<int>& ans) {
    Node* cur = root->left;
    while(cur != NULL) {
        if(!isLeaf(cur)) ans.push_back(cur->data);
        if(cur->left != NULL) cur = cur->left;
        else cur = cur->right;
    }
}

// Similar to preOrder Traversal
void addLeaves(Node* root, vector<int>& ans) {
    if(root == NULL) return ;
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return ;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(Node* root, vector<int>& ans) {
    Node* cur = root->right;
    vector<int> temp;
    while(cur != NULL) {
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right != NULL) cur = cur->right;
        else cur = cur->left;
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
} 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    vector<int> ans = boundaryTraversal(root);

    cout<<"BoundaryTraversal : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}