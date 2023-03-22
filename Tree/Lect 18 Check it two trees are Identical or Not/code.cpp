// Problem: Check if two trees are Identical or Not

//        Tree1
//         1
//       /  \
//      2    3
//         /  \ 
//        4    5

//        Tree2
//         1
//       /  \
//      2    3
//         /  \ 
//        4    5

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree.

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

bool check(Node* root1, Node* root2) {
    if(root1 == NULL || root2 == NULL) {
        return (root1 == NULL && root2 == NULL);
    }

    if(root1->data != root2->data) return 0;
    bool left = check(root1->left, root2->left);
    bool right = check(root1->right, root2->right);
    return left && right;
}

int main(){
    // Tree1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right= new Node(5);

    // Tree2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->right= new Node(5);

    if(check(root1, root2)) cout<<"Two Trees are Identical"<<endl;
    else cout<<"Two Trees are Not Identical"<<endl;
    return 0;
}