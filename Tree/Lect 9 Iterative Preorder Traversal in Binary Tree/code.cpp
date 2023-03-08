// Problem: Iterative Preorder Traversal in Binary Tree

//       Tree
//        1
//      /  \
//     2    3
//   /  \
//  4    5
//     /  \
//    6    7

// Trick to Remember Preorder: Root Left Right

// Preorder: [1, 2, 3, 4, 5, 6, 7]

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

vector<int> iterativePreOrder(Node* root) {
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<Node *> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        preOrder.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return preOrder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> arr = iterativePreOrder(root);
    cout<<"IterativePreOrder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}