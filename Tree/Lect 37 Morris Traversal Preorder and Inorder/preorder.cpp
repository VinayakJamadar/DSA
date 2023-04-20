// Problem: Morris Traversal Preorder and Inorder

#include<bits/stdc++.h>
using namespace std;

//           Tree
//             1
//          /    \
//         2      3
//       /  \
//      4    5
//            \
//             6

// Trick to Remember Preorder: Root Left Right

// Preorder: [1, 2, 4, 5, 6, 3]

// Time Complexity: O(2n) = O(n)

// Space Complexity: O(1)
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

vector<int> preOrder(Node* root) {
    vector<int> preorder;

    Node* cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            Node* temp = cur->left;
            while(temp->right && temp->right != cur) {
                temp = temp->right;
            }

            if(temp->right == NULL) {
                temp->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else {
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> arr = preOrder(root);
    cout<<"Inorder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}