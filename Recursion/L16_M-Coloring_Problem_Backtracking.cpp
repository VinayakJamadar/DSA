#include<bits/stdc++.h>
using namespace std;

// Using Adjacency List

// bool isSafe(int node, list<int> G[], int color[], int n, int col) {
//     for (auto &&itr : G[node])
//     {
//         if(color[itr] == col) return false;
//     }
//     return true;
// }

// bool f(int node, list<int> G[], int color[], int n, int m){
//     if(node == n) return true;

//     for (int i = 1; i <= m; i++)
//     {
//         if(isSafe(node, G, color, n, i)){
//             color[node] = i;
//             if(f(node+1, G, color, n, m)) return true;
//             color[node] = 0;
//         }
//     }
//     return false;
// }

// int main(){
//     list<int> G[4] = {
//         {1, 2, 3},
//         {0, 2, 3},
//         {0, 1},
//         {0, 1}
//     };
//     int n = 4, m = 3, color[4] = {0};
//     cout<<"Color of Nodes before Recursive Function Call : [ ";
//     for (auto &&i : color)
//     {
//         cout<<i<<" ";
//     }
//     cout<<"]"<<endl;
    
//     if(f(0, G, color, n, m)) cout<<1;
//     else cout<<0;
//     cout<<endl;

//     cout<<"Color of Nodes After Recursive Function Call : [ ";
//     for (auto &&i : color)
//     {
//         cout<<i<<" ";
//     }
//     cout<<"]"<<endl;
//     return 0;
// }

// Using Adjacency Matrix

bool isSafe(int node, bool G[4][4], int color[], int n, int col) {
    for (int i = 0; i < n; i++)
    {
        // Here in if condition we can use either G[node][i] or G[i][node].
        // Because both are equivalent --> G[node][i] == G[i][node].
        if(i != node and G[node][i] == 1 and color[i] == col) return false;
    }
    return true;
}

bool f(int node, bool G[4][4], int color[], int n, int m){
    if(node == n) return true;

    for (int i = 1; i <= m; i++)
    {
        if(isSafe(node, G, color, n, i)){
            color[node] = i;
            if(f(node+1, G, color, n, m)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main(){
    int n = 4, m = 3, color[4] = {0};
    bool G[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
    };
    cout<<"Color of Nodes before Recursive Function Call : [ ";
    for (auto &&i : color)
    {
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    
    if(f(0, G, color, n, m)) cout<<1;
    else cout<<0;
    cout<<endl;

    cout<<"Color of Nodes After Recursive Function Call : [ ";
    for (auto &&i : color)
    {
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}