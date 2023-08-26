// Problem: Binary Search Tree Iterator in O(H) Space

// Trick to Remember Inorder: Left Node Right
// Trick to Remember Reverse Inorder: Right Node Left
// Note: Reverse Inorder is Sorted in Decreasing order

//              BST
//              7
//          /      \
//         3       15
//               /   \
//              9    20

// Inorder: [3, 7, 9, 15, 20]
// Reverse Inorder: [20, 15, 9, 7, 3]

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

int main(){
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    int next;
    bool hasNext;

    // nextBSTIterator
    cout << "nextBSTIterator" << endl;
    BSTIterator* obj1 = new BSTIterator(root, 0);
    next = obj1->next();
    cout << "next(): " << next << endl;
    next = obj1->next();
    cout << "next(): " << next << endl;
    hasNext = obj1->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj1->next();
    cout << "next(): " << next << endl;
    hasNext = obj1->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj1->next();
    cout << "next(): " << next << endl;
    hasNext = obj1->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj1->next();
    cout << "next(): " << next << endl;
    hasNext = obj1->hasNext();
    cout << "hasNext(): " << hasNext << endl;

    // beforeBSTIterator
    cout << "\nbeforeBSTIterator" << endl;
    BSTIterator* obj2 = new BSTIterator(root, 1);
    next = obj2->next();
    cout << "next(): " << next << endl;
    next = obj2->next();
    cout << "next(): " << next << endl;
    hasNext = obj2->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj2->next();
    cout << "next(): " << next << endl;
    hasNext = obj2->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj2->next();
    cout << "next(): " << next << endl;
    hasNext = obj2->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    next = obj2->next();
    cout << "next(): " << next << endl;
    hasNext = obj2->hasNext();
    cout << "hasNext(): " << hasNext << endl;
    return 0;
}