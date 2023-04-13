// Problem: Maximum Path Sum in Binary Tree

// Method 2: Optimization Approach (i.e Optimizing pathSum function) 
// (Modifying the Brute Force Approach of Diameter or Height of Binary Tree)


// Definition of Maximum Path Sum in Binary Tree
// 1. Longest path Sum between 2 nodes
// 2. Path does not need to pass via root
// 3. In a Path Every node appears only once


//        Tree
//        -10
//       /   \
//      9    20
//         /   \ 
//       15     7

// Maximum Path Sum: 42

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

// For each node there can be four ways that the max path goes through the node: 

// 1. Node only 
// 2. Max path through Node + Left Child
// 3. Max path through Node + Right Child
// 4. Max path through Node + Left Child + Right Child

int pathSum(Node* root, int& maxPathSum) {
    if(root == NULL) return 0;

    int leftPathSum = pathSum(root->left, maxPathSum);
    int rightPathSum = pathSum(root->right, maxPathSum);

    // 1. Node only 
    maxPathSum = max(maxPathSum, root->data);
    // 2. Max path through Node + Left Child
    maxPathSum = max(maxPathSum, root->data + leftPathSum);
    // 3. Max path through Node + Right Child
    maxPathSum = max(maxPathSum, root->data + rightPathSum);
    // 4. Max path through Node + Left Child + Right Child
    maxPathSum = max(maxPathSum, root->data + leftPathSum + rightPathSum);

    return max(root->data, root->data + max(leftPathSum, rightPathSum));
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right= new Node(7);

    int maxPathSum = INT_MIN;
    pathSum(root, maxPathSum);
    cout<<"Maximum Path Sum in Binary Tree: "<<maxPathSum<<endl;
    return 0;
}