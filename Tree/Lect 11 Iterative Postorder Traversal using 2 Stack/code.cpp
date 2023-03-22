// Problem: Iterative Postorder Traversal in Binary Tree using 2 Stack

// Trick to Remember Postorder: Left Right Root

//         Tree
//          1
//       /    \
//     2       3
//   /  \     /
//  4    5   6
//            \
//             7
//              \
//               8

// Inorder: [4, 5, 2, 8, 7, 6, 3, 1]

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

// Space Complexity: O(2*n)
// Reason: Space taken by stack 'st1' as O(n) and stack 'st2' as O(n) to store.

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

vector<int> iterativePostOrder(Node* root) {
    vector<int> postOrder;
    if(root == NULL) return postOrder;

    stack<Node *> st1, st2;
    st1.push(root);
    while(st1.size()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }

    while(st2.size()) {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    vector<int> arr = iterativePostOrder(root);
    cout<<"IterativePostOrder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}