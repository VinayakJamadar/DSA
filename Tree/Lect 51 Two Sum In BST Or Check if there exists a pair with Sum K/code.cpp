// Problem: Two Sum In BST Or Check if there exists a pair with Sum k

// Trick to Remember Inorder: Left Node Right
// Trick to Remember Reverse Inorder: Right Node Left
// Note: Reverse Inorder is Sorted in Decreasing order

//               BST
//                7
//          /         \
//         3          10
//      /    \      /    \
//     2      6    9     11
//   /       /    /
//  1       5    8
//         /
//        4


// k = 16 -> answer: true for 5 + 11
// k = 2 -> answer: sum is not possible with any two different elements
// k = 22 -> answer: sum is not possible with any two different elements

// Inorder: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
// Reverse Inorder: [11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

// Time Complexity: O(n)
// Reason: Using while loop in function 'twoSumInBST' which at worst case iterate for 'n' times is Sum is not possible for any two different elements

// Space Complexity: O(2*h)
// Where h = height of BST
// Reason: Stack stores atleast 'h' nodes for 2 BSTIterators

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

class BSTIterator {
    private:
        stack<Node* > myStack;
        // reverse -> true -> beforeBSTIterator
        // reverse -> false -> nextBSTIterator
        bool reverse = true;
        void pushAll(Node* node) {
            while(node != NULL) {
                myStack.push(node);
                if(reverse) node = node->right;
                else node = node->left;
            }
        }

    public:
        BSTIterator(Node* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        // return whether we have a next largest number of inorder or before smallest number of reverse inorder
        bool hasNext() {
            return !myStack.empty();
        }

        // return the next largest number of inorder or before smallest number of reverse inorder
        int next() {
            Node* node = myStack.top();
            myStack.pop();
            if(reverse) pushAll(node->left);
            else pushAll(node->right);
            return node->data;
        }
};

bool twoSumInBST(Node* root, int k) {
    if(!root) return 0;
    BSTIterator l(root, 0);
    BSTIterator r(root, 1);

    int i = l.next();
    int j = r.next();

    while(i < j) {
        if(i + j == k) return 1;
        else if(i + j < k) i = l.next();
        else j = r.next();
    }
    return 0;
}

int main(){
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(11);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(5);
    root->right->left->left = new Node(8);
    root->left->right->left->left = new Node(4);

    int k = 16;

    cout << "Two Sum In BST for sum " << k << " is " << (twoSumInBST(root, k) ? "" : "not ") << "possible for given BST" << endl;
    return 0;
}