// Problem: Construct a BST from a preorder traversal

// Approach2: bruteForce2 - Constructing a BST by Preorder and Inorder Traversal

//     BST of Given Preorder
//               8
//          /       \
//         5         10
//      /    \         \
//     1     7          12

// Time Complexity: O(n*log(n)) + O(n)
// Reason: O(n*log(n)) for Sorting and O(n) for Constructing a Tree

// Space Complexity: O(n) + O(n)
// Reason: O(n) for Using unordered_map 'inMap' of size n and O(n) for Storing inorder

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

Node * constructTree(vector<int>& preorder, int preStart, int preEnd, vector <int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node * root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root -> left = constructTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root -> right = constructTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    // inMap is used to get the Index of element from Inorder
    unordered_map<int,int> inMap;
    for (int i = inStart; i <= inEnd; i++) {
        inMap[inorder[i]] = i;
    }

    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, inMap);
}

void preOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int main(){
    vector<int> preorder{8, 5, 1, 7, 10, 12};
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    cout<<"Given Preorder : [ ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout<<preorder[i]<<" ";
    }
    cout<<"]"<<endl;
    
    cout<<"Given Inorder : [ ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout<<inorder[i]<<" ";
    }
    cout<<"]"<<endl;

    Node* root = buildTree(preorder, inorder);

    vector<int> pre;
    preOrder(root, pre);
    cout<<"Preorder of Constructed Tree : [ ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout<<pre[i]<<" ";
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