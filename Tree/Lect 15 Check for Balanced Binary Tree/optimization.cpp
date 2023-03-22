// Problem: Check for Balanced Binary Tree

// Method 2: Optimization Approach (i.e Optimizing Height function)

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


// Time Complexity: O(n)
// Reason: As height() using only O(n) i.e Traversing all the nodes

// Space Complexity: O(h)
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

// Approach is while return from height()

// 1. Calculate leftHeight and rightHeight
// 2. If check if left or right is -1 then return -1
// 3. Else if check if abs(leftHeight - rightHeight) > 1 then return -1
// 4. Else return height;

int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight == -1 or rightHeight == -1) return -1;
    else if(abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
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

    if(height(root1) != -1) cout<<"Tree1 is Balanced Binary Tree"<<endl;
    else cout<<"Tree1 is Unbalanced Binary Tree"<<endl;

    if(height(root2) != -1) cout<<"Tree2 is Balanced Binary Tree"<<endl;
    else cout<<"Tree2 is Unbalanced Binary Tree"<<endl;

    return 0;
}