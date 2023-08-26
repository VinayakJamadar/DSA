// Problem: Right and Left View of Binary Tree using Recursive Approach


//        Tree
//          1
//       /    \
//      2      3
//    /  \      \ 
//   4    5     7
//       /
//     6

// LeftView: [1, 2, 4, 6]
// RightView: [1, 3, 7, 6]

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

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


// Logic: First node of every level using Recursive PreOrder Traversal 

void leftView(Node *root, int level, vector<int>& ans) {
    if(root == NULL) return ;

    if(level == ans.size()) ans.push_back(root->data);
    leftView(root->left, level+1, ans);
    leftView(root->right, level+1, ans);
}


// Logic: First node of every level using Recursive Reverse PreOrder Traversal

void rightView(Node *root, int level, vector<int>& ans) {
    if(root == NULL) return ;

    if(level == ans.size()) ans.push_back(root->data);
    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> left, right;

    leftView(root, 0, left);
    cout<<"LeftView : [ ";
    for (int i = 0; i < left.size(); i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<"]"<<endl;

    rightView(root, 0, right);
    cout<<"RightView : [ ";
    for (int i = 0; i < right.size(); i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}