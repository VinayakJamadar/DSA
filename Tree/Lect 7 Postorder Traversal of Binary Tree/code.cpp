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

//      Tree
//        1
//     /    \
//    2      3
//   / \    / \
//  4  5   7   8
//    /       / \
//   6       9   10

void postOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->data);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int> arr;
    postOrder(root, arr);
    cout<<"Postorder : [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}