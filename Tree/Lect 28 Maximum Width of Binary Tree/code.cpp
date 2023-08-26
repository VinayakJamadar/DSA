// Problem: Maximum Width in Binary Tree

// Definition of Width in Binary Tree:
// Number of possible nodes in a level between any 2 nodes

//       Tree1
//         1
//      /    \
//     3      2
//   /  \      \
//  5   3       9

// Maximum Width of Tree1: 4 (Number of Nodes between 5 and 9 at level 3)

//       Tree2
//         1
//      /    \
//     3      2
//   /
//  5

// Maximum Width of Tree2: 2 (Number of Nodes between 3 and 2 at level 2)

//       Tree3
//         1
//       /   \
//      3     2
//     /       \
//    5         4
//   /           \
//  7             6

// Maximum Width of Tree3: 8 (Number of Nodes between 7 and 6 at level 4)

// Time Complexity: O(n)
// Reason: As we traverse all the node of tree

// Space Complexity: O(n)
// Reason: At worst case if all the node are at same level queue store all the n nodes.

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

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

// Approach 1:
// Index nodes as follows
// 1. Index of Root Node = 1
// 2. Index of Left Node of Every Node is = 2*ind
// 3. Index of Right Node of Every Node is = 2*ind+1

// Then Answer is Max(lastNodeIndex - firstNodeIndex + 1) at Every Level

// Disadvantage in Approach 1:
// Consider a Skew Tree and Number of Nodes = 10^5
// Then while Index we will get Out of Bound Error as last node Index = 2^(10^5)


// Approach 2 (i.e Starts every level Indexing from 1):
// Index nodes as follows 
// 1. Index of Root Node = 1
// 2. Index of Left Node of Every Node is = 2*(ind-1)
// 3. Index of Right Node of Every Node is = 2*(ind-1)+1

// Then Answer is Max(lastNodeIndex - firstNodeIndex + 1) at Every Level

int maximumWidth(Node *root) {
    int ans = 0;
    if(root == NULL) return ans;
    queue<pair<Node *, int>> q;
    q.push({root, 1});

    while(!q.empty()) {
        int size = q.size();
        int first, last;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front().first;
            int ind = q.front().second;
            q.pop();
            if(i == 0) first = ind;
            if(i == size-1) last = ind;
            if(node->left != NULL) q.push({node->left, 2*(ind-1)});
            if(node->right != NULL) q.push({node->right, 2*(ind-1)+1});
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(7);
    root->right->right->right = new Node(6);

    cout << "Maximum Width of Binary Tree: " << maximumWidth(root) << endl;
    return 0;
}