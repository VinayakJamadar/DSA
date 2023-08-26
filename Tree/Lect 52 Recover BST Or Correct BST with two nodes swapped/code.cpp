// Problem: Recover BST Correct BST with two nodes swapped

//       Before Recover BST1
//               8
//          /        \
//         5          7
//      /    \     /    \
//     4     12   10    14
//          /          /
//         6         13

//       After Recover BST1
//               8
//          /        \
//         5         12
//      /    \     /    \
//     4     7   10    14
//          /          /
//         6         13

// Inorder of Binary Tree1 Before Recover Tree : [ 4 5 6 12 8 10 7 13 14 ]
// Inorder of Binary Tree1 After Recover Tree : [ 4 5 6 7 8 10 12 13 14 ] 


//       Before Recover BST2
//               8
//          /        \
//         6         12
//      /    \     /    \
//     4     7   10    14
//          /          /
//         5         13

//       After Recover BST2
//               8
//          /        \
//         5         12
//      /    \     /    \
//     4     7   10    14
//          /          /
//         6         13

// Inorder of Binary Tree2 Before Recover Tree : [ 4 6 5 7 8 10 12 13 14 ]
// Inorder of Binary Tree2 After Recover Tree : [ 4 5 6 7 8 10 12 13 14 ] 


// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

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

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node* first = NULL;
Node* previous = NULL;
Node* middle = NULL;
Node* last = NULL;

void findViolation(Node* root) {
    if(root == NULL) return ;

    findViolation(root->left);

    if(previous != NULL && (root->data < previous->data)) {
        // If this is first violation, mark these two nodes as
        // 'first' and 'middle'
        if(first == NULL) {
            first = previous;
            middle = root;
        }
        // If this is second violation, mark this node as last
        else {
            last = root;
        }
    }

    // Mark this node (i.e root) as previous
    previous = root;

    findViolation(root->right);
}

void recoverTree(Node* root) {
    first = middle = last = NULL;
    // previous = new Node(INT_MIN);
    findViolation(root);
    if(first && last) swap(first->data, last->data);
    else if(first && middle) swap(first->data, middle->data);
}

int main(){
    Node* root1 = new Node(8);
    root1->left = new Node(5);
    root1->right = new Node(7);
    root1->left->left = new Node(4);
    root1->left->right = new Node(12);
    root1->right->left = new Node(10);
    root1->right->right = new Node(14);
    root1->left->right->left = new Node(6);
    root1->right->right->left = new Node(13);

    vector<int> before1, after1;
    inOrder(root1, before1);
    cout<<"Inorder of Binary Tree1 Before Recover Tree : [ ";
    for (int i = 0; i < before1.size(); i++)
    {
        cout<<before1[i]<<" ";
    }
    cout<<"]"<<endl;

    recoverTree(root1);

    inOrder(root1, after1);
    cout<<"Inorder of Binary Tree1 After Recover Tree : [ ";
    for (int i = 0; i < after1.size(); i++)
    {
        cout<<after1[i]<<" ";
    }
    cout<<"]"<<endl;


    Node* root2 = new Node(8);
    root2->left = new Node(6);
    root2->right = new Node(12);
    root2->left->left = new Node(4);
    root2->left->right = new Node(7);
    root2->right->left = new Node(10);
    root2->right->right = new Node(14);
    root2->left->right->left = new Node(5);
    root2->right->right->left = new Node(13);

    vector<int> before2, after2;
    inOrder(root2, before2);
    cout<<"Inorder of Binary Tree2 Before Recover Tree : [ ";
    for (int i = 0; i < before2.size(); i++)
    {
        cout<<before2[i]<<" ";
    }
    cout<<"]"<<endl;

    recoverTree(root2);

    inOrder(root2, after2);
    cout<<"Inorder of Binary Tree2 After Recover Tree : [ ";
    for (int i = 0; i < after2.size(); i++)
    {
        cout<<after2[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}