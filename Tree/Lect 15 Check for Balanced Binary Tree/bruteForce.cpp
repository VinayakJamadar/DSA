// Problem: Check for Balanced Binary Tree

// Method 1: Brute Force Approach

//        Tree1
//         3
//       /  \
//      9    20
//         /  \ 
//       15    7

//          Tree2
//            1
//          /  \
//         3    2
//       /  \
//      5    4
//    /  \
//   6    7


// Time Complexity: O(n^2)
// Reason: As check() traverse all the nodes takes O(n) and For every node height() takes O(n). So it is O(n*n) ~ O(n^2)

// Space Complexity: O(2*h)
// Where h = height of tree

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

int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

bool check(Node* root) {
    if(root == NULL) return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(abs(leftHeight - rightHeight) > 1) return 0;

    bool leftCheck = check(root->left);
    bool rightCheck = check(root->right);

    return leftCheck & rightCheck;
}

int main(){
    // Tree1
    Node* root1 = new Node(3);
    root1->left = new Node(9);
    root1->right = new Node(20);
    root1->right->left = new Node(15);
    root1->right->right= new Node(7);

    // Tree2
    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->left = new Node(5);
    root2->left->right = new Node(4);
    root2->left->left->left= new Node(7);
    root2->left->left->right= new Node(6);

    if(check(root1)) cout<<"Tree1 is Balanced Binary Tree"<<endl;
    else cout<<"Tree1 is Unbalanced Binary Tree"<<endl;

    if(check(root2)) cout<<"Tree2 is Balanced Binary Tree"<<endl;
    else cout<<"Tree2 is Unbalanced Binary Tree"<<endl;
    return 0;
}