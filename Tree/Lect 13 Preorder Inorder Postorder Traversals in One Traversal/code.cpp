// Problem: Preorder Inorder Postorder in One Traversal

// Trick to Remember Preorder: Root Left Right
// Trick to Remember Inorder: Left Root Right
// Trick to Remember Postorder: Left Right Root

//      Tree
//        1
//     /     \
//    2       5
//   / \     / \
//  3   4   6   7

// Preorder: [1, 2, 3, 4, 5, 6, 7]
// Inorder: [3, 2, 4, 1, 6, 5, 7]
// Postorder: [3, 4, 2, 6, 7, 5, 1]

// Time Complexity: O(3*n)
// Reason: As we are Iterative 3 times for every node of tree.

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

vector<int> preOrder, inOrder, postOrder;

void allInOneTraversal(Node* root) {
    if(root == NULL) return ;

    stack<pair<Node *, int>> st;
    st.push({root, 1});
    
    while(!st.empty()) {
        auto node = st.top();
        st.pop();

        // this is part of preOrder
        // increment 1 to 2
        // If exist push the left side of the node
        if(node.second == 1) {
            preOrder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->left != NULL) {
                st.push({node.first->left, 1});
            }
        }
        // this is part of inOrder
        // increment 2 to 3
        // If exist push the right side of the node
        else if(node.second == 2) {
            inOrder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first->right != NULL) {
                st.push({node.first->right, 1});
            }
        }
        // this is part of postOrder
        // don't increment
        // don't push anything
        else {
            postOrder.push_back(node.first->data);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    allInOneTraversal(root);

    cout<<"PreOrder : [ ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout<<preOrder[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"InOrder : [ ";
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout<<inOrder[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"PostOrder : [ ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout<<postOrder[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}