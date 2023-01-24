#include<bits/stdc++.h>
using namespace std;

class Node{
    int val;
    Node *left, *right;

    public:
        Node() {
            val = 0;
            left = NULL, right = NULL;
        }
        Node(int v) {
            val = v;
            left = NULL, right = NULL;
        }
        Node(Node* t) {
            val = t->val;
            left = t->left, right = t->right;
        }
};

int main(){
    stack<Node> st;
    Node* root;
    st.push(root);
    while(!st.empty()) {
        
    }
    return 0;
}
