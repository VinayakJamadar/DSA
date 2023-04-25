// Problem: Kth Smallest and Largest Element in BST

// Note: Inorder Traversal of BST is always Sorted

//               BST
//                8
//          /         \
//         5           12
//      /     \      /    \
//     2       7    10    13
//   /  \     /
//  1   3    6      
//       \
//        4

// Trick to Remember Inorder: Left Root Right
// Inorder: [1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 13]

// Time Complexity: O(log2(n)) or O(h)
// Reason: As we traverse only log2(n) nodes
// Where h = height of BST

// Space Complexity: O(1)
// Reason: Not using any Data Structure

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

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL) return ;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node* kthLargest(Node* root,int& k)
{
	if(root == NULL) return NULL;
	
	Node* right = kthLargest(root->right, k);
	if(right != NULL) return right;
	
	k--;
    if(k == 0) return root;
	
	Node* left = kthLargest(root->left, k);
	if(left != NULL) return left;

	return NULL;
}

Node* kthSmallest(Node* root,int& k)
{
	if(root == NULL) return NULL;
	
	Node* left = kthSmallest(root->left, k);
	if(left != NULL) return left;
	
	k--;
    if(k == 0) return root;
	
	Node* right = kthSmallest(root->right, k);
	if(right != NULL) return right;

	return NULL;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(13);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(6);
    root->left->left->right->right = new Node(4);

    vector<int> arr;
    inOrder(root, arr);
    cout << "Inorder: [ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;

    int k = 4;
    cout << k << "th Smallest Element is: " ;
    cout << kthSmallest(root, k)->data << endl;

    k = 4;
    cout << k << "th Largest Element is: ";
    cout << kthLargest(root, k)->data << endl;
    return 0;
}