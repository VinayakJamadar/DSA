// Problem: Iterative Postorder Traversal in Binary Tree using 1 Stack

// Trick to Remember Postorder: Left Right Root

//         Tree
//          1
//       /    \
//     2       7
//   /        /
//  3        8
//   \
//    4
//     \
//      5
//       \
//        6

// Postorder: [6, 5, 4, 3, 2, 8, 7, 1]

// Time Complexity: O(2*n)
// Reason: O(n) for going into the depth i.e using Outer 'while' loop and O(n) while backtracking from stack 'st' i.e using Inner 'while' loop.

// Space Complexity: O(n)
// Reason: Space taken by stack to store all the nodes of tree.

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

    Node *cur = root, *temp;
    stack<Node *> st;
    while(cur != NULL or !st.empty()) {
        if(cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty() and temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else {
                cur = temp;
            }
        }
    }
    return postOrder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->right = new Node(5);
    root->left->left->right->right->right = new Node(6);
    root->right = new Node(7);
    root->right->left = new Node(8);

    vector<int> arr = iterativePostOrder(root);
    cout<<"IterativePostOrder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}