// Problem: Construct the Binary Tree from Postorder and Inorder Traversal

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(n)
// Reason: Using unordered_map 'inMap' of size n

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

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

Node * constructTree(vector<int>& postorder, int postStart, int postEnd, vector <int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
    if(postStart > postEnd || inStart > inEnd) return NULL;

    Node * root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root -> left = constructTree(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);
    root -> right = constructTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder) {
    int postStart = 0, postEnd = postorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    // inMap is used to get the Index of element from Inorder
    unordered_map<int,int> inMap;
    for (int i = inStart; i <= inEnd; i++) {
        inMap[inorder[i]] = i;
    }

    return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, inMap);
}

void postOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->data);
}

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int main(){
    vector<int> postorder{40,50,20,60,30,10};
    vector<int> inorder{40,20,50,10,60,30};

    cout<<"Given Postorder : [ ";
    for (int i = 0; i < postorder.size(); i++)
    {
        cout<<postorder[i]<<" ";
    }
    cout<<"]"<<endl;
    
    cout<<"Given Inorder : [ ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout<<inorder[i]<<" ";
    }
    cout<<"]"<<endl;

    Node* root = buildTree(postorder, inorder);

    vector<int> post;
    postOrder(root, post);
    cout<<"Postorder of Constructed Tree : [ ";
    for (int i = 0; i < post.size(); i++)
    {
        cout<<post[i]<<" ";
    }
    cout<<"]"<<endl;

    vector<int> in;
    inOrder(root, in);

    cout<<"Inorder of Constructed Tree : [ ";
    for (int i = 0; i < in.size(); i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}