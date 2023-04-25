// Problem: Before Binary Search Tree Iterator in O(H) Space

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

class beforeBSTIterator {
    private:
        stack<Node* > myStack;
        void pullAllRightNodes(Node* node) {
            while(node != NULL) {
                myStack.push(node);
                node = node->right;
            }
        }

    public:
        beforeBSTIterator(Node* root) {
            pullAllRightNodes(root);
        }
        // return whether we have a before smallest number
        bool hasBefore() {
            return !myStack.empty();
        }

        // return the before smallest number
        int before() {
            Node* node = myStack.top();
            myStack.pop();
            pullAllRightNodes(node->left);
            return node->data;
        }
};

int main(){
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    beforeBSTIterator* obj = new beforeBSTIterator(root);
    int before;
    bool hasBefore;
    before = obj->before();
    cout << "before(): " << before << endl;
    before = obj->before();
    cout << "before(): " << before << endl;
    hasBefore = obj->hasBefore();
    cout << "hasBefore(): " << hasBefore << endl;
    before = obj->before();
    cout << "before(): " << before << endl;
    hasBefore = obj->hasBefore();
    cout << "hasBefore(): " << hasBefore << endl;
    before = obj->before();
    cout << "before(): " << before << endl;
    hasBefore = obj->hasBefore();
    cout << "hasBefore(): " << hasBefore << endl;
    before = obj->before();
    cout << "before(): " << before << endl;
    hasBefore = obj->hasBefore();
    cout << "hasBefore(): " << hasBefore << endl;
    return 0;
}