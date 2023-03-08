// Problem: Iterative Inorder Traversal in Binary Tree

// Trick to Remember Inorder: Left Root Right

//       Tree
//        1
//      /  \
//     2    3
//   /  \
//  4    5
//     /  \
//    6    7

// Inorder: [4, 2, 6, 5, 7, 1, 3]

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

vector<int> iterativeInOrder(Node* root) {
    vector<int> inOrder;
    if(root == NULL) return inOrder;

    stack<Node *> st;
    while(1) {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            if(st.empty()) break;
            root = st.top();
            st.pop();
            inOrder.push_back(root->data);
            root = root->right;
        }
    }
    return inOrder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> arr = iterativeInOrder(root);
    cout<<"IterativeInOrder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}