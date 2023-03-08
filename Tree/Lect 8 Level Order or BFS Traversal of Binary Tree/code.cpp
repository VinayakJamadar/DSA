#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(n)
// Reason: At worst case if all the node are at same level queue store all the n nodes.

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

//      Tree
//        1
//     /    \
//    2      3
//   / \    / \
//  4  5   6   7

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = levelOrder(root);
    cout<<"LevelOrder : [ "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}