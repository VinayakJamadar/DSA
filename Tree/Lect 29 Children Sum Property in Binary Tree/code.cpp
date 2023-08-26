// Problem: Children Sum Property in Binary Tree

// Definition of Children Sum Property:
// For every internal node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

// Possible Operations
// 1. The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
// 2. A value for a NULL node can be assumed as 0.
// 3. You are not allowed to change the structure of the given binary tree.


// Binary Tree Without Children Sum Property
//        Tree1
//         50
//       /    \ 
//      7      2
//     / \    / \ 
//    3  5   1  30

// Binary Tree With Children Sum Property
//         Tree1
//          200
//        /     \ 
//     100      100
//     / \     /  \ 
//   50  50   50  50

// Binary Tree Without Children Sum Property
//        Tree2
//         40
//       /    \ 
//      10     2
//     / \    / \ 
//    3  5   1  30

// Binary Tree With Children Sum Property
//         Tree2
//          200
//        /     \ 
//     100      100
//     / \     /  \ 
//   50  50   50  50

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(h), where h = height of tree
// Reason: Space taken by user defined stack which store at most nodes equal to height of tree.

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

// Similar to Postorder Traversal
void reorder(Node* root) {
    if (root == NULL) return;
    
    int child = 0;
    if (root -> left) {
        child += root -> left -> data;
    }
    if (root -> right) {
        child += root -> right -> data;
    }

    if (child < root -> data) {
        if (root -> left) root -> left -> data = root -> data;
        if (root -> right) root -> right -> data = root -> data;
    }

    reorder(root -> left);
    reorder(root -> right);

    int total = 0;
    if (root -> left) total += root -> left -> data;
    if (root -> right) total += root -> right -> data;
    root -> data = total;
}

void postOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->data);
}

int main(){
    Node* root1 = new Node(50);
    root1->left = new Node(7);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(5);
    root1->right->left = new Node(1);
    root1->right->right = new Node(30);

    vector<int> before1, after1;
    postOrder(root1, before1);
    cout<<"Postorder of Binary Tree1 Before Reorder : [ ";
    for (int i = 0; i < before1.size(); i++)
    {
        cout<<before1[i]<<" ";
    }
    cout<<"]"<<endl;

    reorder(root1);

    postOrder(root1, after1);
    cout<<"Postorder of Binary Tree1 After Reorder : [ ";
    for (int i = 0; i < after1.size(); i++)
    {
        cout<<after1[i]<<" ";
    }
    cout<<"]"<<endl;
    
    
    Node* root2 = new Node(40);
    root2->left = new Node(10);
    root2->right = new Node(2);
    root2->left->left = new Node(3);
    root2->left->right = new Node(5);
    root2->right->left = new Node(1);
    root2->right->right = new Node(30);

    vector<int> before2, after2;
    postOrder(root2, before2);
    cout<<"\nPostorder of Binary Tree2 Before Reorder : [ ";
    for (int i = 0; i < before2.size(); i++)
    {
        cout<<before2[i]<<" ";
    }
    cout<<"]"<<endl;

    reorder(root2);

    postOrder(root2, after2);
    cout<<"Postorder of Binary Tree2 After Reorder : [ ";
    for (int i = 0; i < after2.size(); i++)
    {
        cout<<after2[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}