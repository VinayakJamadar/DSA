// Problem: Top View of Binary Tree


//        Tree
//          1
//       /    \
//      2      3
//    /  \      \ 
//   4    5     7
//       /
//     6

// TopView: [4, 2, 1, 3, 7]

// Time Complexity: O(n*log(n))
// Reason: As we traverse all the node of tree it takes O(n) and With in it we are using map ds.find() which takes O(log(n))

// Space Complexity: O(2*n)
// Reason: In Worst Case O(n) for map 'ds' and O(n) for queue 'q'

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

// Approach:
// We assign a Vertical Line Number to Every Node; Like node(x) where x = vertical line number
// 1. For root of Tree; root(x) = (0)
// 2. For left child of any node; leftChild(x) = parentNode(x-1)
// 3. For right child of any node; rightChild(x) = parentNode(x+1)

// We can Assign this above coordinates using any traversal like Preorder, Inorder, Postorder or Levelorder.
// Usually it is easy to use Levelorder traversal.

// Example

//        Tree
//          1
//       /    \
//      2      3
//    /  \      \ 
//   4    5     7
//       /
//     6

//              Coordinates
//                 1(0)
//              /       \
//          2(-1)       3(1)
//        /     \          \ 
//    4(-2)     5(0)       7(2)
//             /
//          6(-1)


vector<int> topView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> ds;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto itr = q.front();
            q.pop();
            Node* node = itr.first;
            int x = itr.second;
            if(ds.find(x) == ds.end()) ds[x] = node->data;
            if(node->left != NULL) q.push({node->left, x-1});
            if(node->right != NULL) q.push({node->right, x+1});
        }
    }

    for (auto i : ds)
    {
        ans.push_back(i.second);
    }
    
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = topView(root);
    cout<<"TopView : [ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}