// Problem: Maximum Path Sum in Binary Tree

// Method 1: Brute Force Approach 
// (Modifying the Brute Force Approach of Diameter or Height of Binary Tree)


// Definition of Maximum Path Sum in Binary Tree
// 1. Maximum path Sum between 2 nodes
// 2. Path does not need to pass via root
// 3. In a Path Every node appears only once


//        Tree
//        -10
//       /   \
//      9    20
//         /   \ 
//       15     7

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

// For each node there can be four ways that the max path goes through the node: 

// 1. Node only 
// 2. Max path through Node + Left Child
// 3. Max path through Node + Right Child
// 4. Max path through Node + Left Child + Right Child

int pathSum(Node* root) {
    if(root == NULL) return 0;

    int leftPathSum = pathSum(root->left);
    int rightPathSum = pathSum(root->right);

    return max(root->data, root->data + max(leftPathSum, rightPathSum));
}

int maxPathSum;

void findMaxPathSum(Node* root) {
    if(root == NULL) return ;

    int leftPathSum = pathSum(root->left);
    int rightPathSum = pathSum(root->right);

    // 1. Node only 
    maxPathSum = max(maxPathSum, root->data);
    // 2. Max path through Node + Left Child
    maxPathSum = max(maxPathSum, root->data + leftPathSum);
    // 3. Max path through Node + Right Child
    maxPathSum = max(maxPathSum, root->data + rightPathSum);
    // 4. Max path through Node + Left Child + Right Child
    maxPathSum = max(maxPathSum, root->data + leftPathSum + rightPathSum);

    findMaxPathSum(root->left);
    findMaxPathSum(root->right);
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right= new Node(7);

    maxPathSum = 0;
    findMaxPathSum(root);
    cout<<"Maximum Path Sum in Binary Tree: "<<maxPathSum<<endl;
    return 0;
}