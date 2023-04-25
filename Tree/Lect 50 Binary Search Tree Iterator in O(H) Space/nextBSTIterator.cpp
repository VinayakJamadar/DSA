// Problem: next Binary Search Tree Iterator in O(H) Space

// Trick to Remember Inorder: Left Node Right

//              BST
//              7
//          /      \
//         3       15
//               /   \
//              9    20

// Inorder: [3, 7, 9, 15, 20]

// Time Complexity: O(1)
// Reason: Nearly equal to O(1)

// Space Complexity: O(h)
// Where h = height of BST
// Reason: Stack stores atleast 'h' nodes

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

class nextBSTIterator {
    private:
        stack<Node* > myStack;
        void pushAllLeftNodes(Node* node) {
            while(node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }

    public:
        nextBSTIterator(Node* root) {
            pushAllLeftNodes(root);
        }

        // return whether we have a next smallest number
        bool hasNext() {
            return !myStack.empty();
        }

        // return the next smallest number
        int next() {
            Node* node = myStack.top();
            myStack.pop();
            pushAllLeftNodes(node->right);
            return node->data;
        }
};

int main(){
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    nextBSTIterator* obj = new nextBSTIterator(root);
    int next;
    bool hasNext;
    next = obj->next();
    cout << "next(): " << next << endl;
    next = obj->next();
    cout << "next(): " << next << endl;
    hasNext = obj->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj->next();
    cout << "next(): " << next << endl;
    hasNext = obj->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj->next();
    cout << "next(): " << next << endl;
    hasNext = obj->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj->next();
    cout << "next(): " << next << endl;
    hasNext = obj->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    return 0;
}