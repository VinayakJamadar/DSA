#include<bits/stdc++.h>
using namespace std;

// Order of Recursion Call in Direction --> D, L, R, U

// With if statements

// void f(int i, int j, int n, string move, vector<string>& ans, vector<vector<bool>>& visited, vector<vector<bool>>& board){
//     // Base Case
//     if(i == n-1 and j == n-1) {
//         ans.push_back(move);
//         return ;
//     }

//     // Recursive Case

//     // Down
//     if(i+1 < n and board[i+1][j] and visited[i+1][j] == 0) {
//         visited[i][j] = 1;
//         f(i+1, j, n, move+'D', ans, visited, board);
//         visited[i][j] = 0;
//     }

//     // Left
//     if(j-1 >= 0 and board[i][j-1] and visited[i][j-1] == 0) {
//         visited[i][j] = 1;
//         f(i, j-1, n, move+'L', ans, visited, board);
//         visited[i][j] = 0;
//     }

//     // Right
//     if(j+1 < n and board[i][j+1] and visited[i][j+1] == 0) {
//         visited[i][j] = 1;
//         f(i, j+1, n, move+'R', ans, visited, board);
//         visited[i][j] = 0;
//     }

//     // Up
//     if(i-1 >= 0 and board[i-1][j] and visited[i-1][j] == 0) {
//         visited[i][j] = 1;
//         f(i-1, j, n, move+'U', ans, visited, board);
//         visited[i][j] = 0;
//     }
// }

// int main(){
//     int n = 4;
//     vector<string> ans;
//     vector<vector<bool>> v (n, vector<bool> (n, 0));
//     vector<vector<bool>> b = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}
//     };
//     if(b[0][0] and b[n-1][n-1]) f(0, 0, n, "", ans, v, b);
//     for (auto &&i : ans)
//     {
//         cout<<i<<" ";
//     }
//     return 0;
// }


// Without if statements

void f(int i, int j, int n, string move, vector<string>& ans, vector<vector<bool>>& visited, vector<vector<bool>>& board){
    // Base Case
    if(i == n-1 and j == n-1) {
        ans.push_back(move);
        return ;
    }

    // Recursive Case

    // Down
    if(i+1 < n and board[i+1][j] and visited[i+1][j] == 0) {
        visited[i][j] = 1;
        f(i+1, j, n, move+'D', ans, visited, board);
        visited[i][j] = 0;
    }

    // Left
    if(j-1 >= 0 and board[i][j-1] and visited[i][j-1] == 0) {
        visited[i][j] = 1;
        f(i, j-1, n, move+'L', ans, visited, board);
        visited[i][j] = 0;
    }

    // Right
    if(j+1 < n and board[i][j+1] and visited[i][j+1] == 0) {
        visited[i][j] = 1;
        f(i, j+1, n, move+'R', ans, visited, board);
        visited[i][j] = 0;
    }

    // Up
    if(i-1 >= 0 and board[i-1][j] and visited[i-1][j] == 0) {
        visited[i][j] = 1;
        f(i-1, j, n, move+'U', ans, visited, board);
        visited[i][j] = 0;
    }
}

int main(){
    int n = 4;
    vector<string> ans;
    vector<vector<bool>> v (n, vector<bool> (n, 0));
    vector<vector<bool>> b = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    // vector<int
    if(b[0][0] and b[n-1][n-1]) f(0, 0, n, "", ans, v, b);
    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}