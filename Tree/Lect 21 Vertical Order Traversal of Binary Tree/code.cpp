// Problem: Vertical Order Traversal of Binary Tree


//        Tree
//          1
//       /    \
//      2      3
//    /  \    / \ 
//   4   10  9  10
//    \
//     5
//      \
//       6

// VerticalOrder: [
//     [4],
//     [2, 5],
//     [1, 9, 10, 6],
//     [3],
//     [10]
// ]

// Time Complexity: O(n*log(n))
// Reason: As we traverse all the node of tree it takes O(n) and With in it we are using map.find() which takes O(log(n))

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
// We assign a coordinates to Every Node; Like node(x, y) where x = vertical line number, y = level of node
// 1. For root of Tree; root(x, y) = (0, 0)
// 2. For left child of any node; leftChild(x, y) = parentNode(x-1, y+1)
// 3. For right child of any node; rightChild(x, y) = parentNode(x+1, y+1)

// We can Assign this above coordinates using any traversal like Preorder, Inorder, Postorder or Levelorder.
// Usually it is easy to use Levelorder traversal.

// Example

//        Tree
//          1
//       /    \
//      2      3
//    /  \    / \ 
//   4   10  9  10
//    \
//     5
//      \
//       6

//                Coordinates
//                  1(0, 0)
//              /            \
//       2(-1, 1)            3(1, 1)
//       /      \            /      \ 
// 4(-2, 2)    10(0, 2)  9(0, 2)    10(2, 2)
//      \
//       5(-1, 3)
//        \
//         6(0, 4)

vector<vector<int>> verticalOrder(Node *root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    map<int, map<int, multiset<int>>> ds;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto itr = q.front();
            q.pop();
            Node* node = itr.first;
            int x = itr.second.first, y = itr.second.second;
            ds[x][y].insert(node->data);
            if(node->left != NULL) q.push({node->left, {x-1, y+1}});
            if(node->right != NULL) q.push({node->right, {x+1, y+1}});
        }
    }

    for (auto i : ds)
    {
        vector<int> col;
        for(auto j : i.second) {
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }
    
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    vector<vector<int>> ans = verticalOrder(root);
    cout<<"VerticalOrder : [ "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}