// Problem: Flatten a Binary Tree to Linked List

// Approach 3: Iterative Reverse Postorder Traversal

#include<bits/stdc++.h>
using namespace std;

//           Tree
//             1
//          /    \
//         2      5
//       /  \      \
//      3    4      6
//                 /
//                7

// Trick to Remember Preorder: Root Left Right

// Preorder: [1, 2, 3, 4, 5, 6, 7]

// Trick to Remember Reverse Postorder: Right Left Root

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(n)
// Reason: As we are using Threaded Binary Tree. So we are not using any Auxiliary Stack Space

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

void flatten(Node* root) {
    Node* cur = root;
    while(cur) {
        if(cur->left) {
            Node* pre = cur->left;
            while(pre->right) {
                pre = pre->right;
            }

            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

void preOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    
    vector<int> before;
    preOrder(root, before);
    cout<<"Preorder Before Flatten : [ ";
    for (int i = 0; i < before.size(); i++)
    {
        cout<<before[i]<<" ";
    }
    cout<<"]"<<endl;

    flatten(root);

    vector<int> after;
    preOrder(root, after);
    cout<<"Preorder After Flatten : [ ";
    for (int i = 0; i < after.size(); i++)
    {
        cout<<after[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}