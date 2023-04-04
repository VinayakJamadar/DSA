// Problem: Right and Left View of Binary Tree using Iterative Approach


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


// Logic: First node of every level

vector<int> leftView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();
            if(i == 0) ans.push_back(node->data); 
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }

    return ans;
}


// Logic: Last node of every level

vector<int> rightView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();
            if(i == size-1) ans.push_back(node->data); 
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;

    ans = leftView(root);
    cout<<"LeftView : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]"<<endl;

    ans = rightView(root);
    cout<<"RightView : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}