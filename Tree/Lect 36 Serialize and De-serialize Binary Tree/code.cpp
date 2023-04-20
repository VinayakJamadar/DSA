// Problem: Serialize and De-serialize Binary Tree

// Serialization: binary tree can be serialized to a string
// De-serialization: string can be deserialized to the original binary tree structure

//        Given Tree
//             1
//          /    \
//         2     13
//              /  \
//             4    5

// Serialize: 
// 1,2,13,#,#,4,5,#,#,#,#

// Deserialize:
//             1
//          /    \
//         2     13
//              /  \
//             4    5

// Time Complexity: O(n)
// Reason: As we traverse all the node using level order traversal of tree

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

// Encodes a tree to a single string.
string serialize(Node* root) {
    if(!root) return "";
    
    string s ="";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        if(node==NULL) s.append("#,");
        else s.append(to_string(node->data)+',');
        if(node != NULL){
            q.push(node->left);
            q.push(node->right);            
        }
    }
    return s;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if(data.size() == 0) return NULL; 
    stringstream s(data);
    string str; 
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node*> q; 
    q.push(root); 
    while(!q.empty()) {
        
        Node *node = q.front(); 
        q.pop(); 
        
        getline(s, str, ',');
        if(str == "#") {
            node->left = NULL; 
        }
        else {
            Node* leftNode = new Node(stoi(str)); 
            node->left = leftNode; 
            q.push(leftNode); 
        }
        
        getline(s, str, ',');
        if(str == "#") {
            node->right = NULL; 
        }
        else {
            Node* rightNode = new Node(stoi(str)); 
            node->right = rightNode;
            q.push(rightNode); 
        }
    }
    return root; 
}

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
    root->right = new Node(13);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Serialize: [ " << serialize(root) << " ]\n" << endl;

    vector<vector<int>> ans = levelOrder(root);
    cout<<"LevelOrder Traversal of Deserialize is: "<<endl;
    cout<<"[ "<<endl;
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