#include<bits/stdc++.h>
using namespace std;

// leftRow 
// . . . . . . Q

// upperLeftDiagonal
//  .
//    .
//      .
//        .
//          .
//            Q

// lowerRightDiagonal
//            Q
//          .
//        .
//      .
//    .
//  .

// Approach 1 --> Simple Backtracking

// bool isSafe(int row, int col, int n, vector<string>& board) {
//     // upperLeftDiagonal
//     int itrRow = row, itrCol = col;
//     while(itrRow >= 0 and itrCol >= 0) {
//         if(board[itrRow][itrCol] == 'Q') return false;
//         --itrRow, --itrCol;
//     }

//     // leftRow
//     itrRow = row, itrCol = col;
//     while(itrCol >= 0) {
//         if(board[itrRow][itrCol] == 'Q') return false;
//         --itrCol;
//     }

//     // lowerRightDiagonal
//     itrRow = row, itrCol = col;
//     while(itrRow < n and itrCol >= 0) {
//         if(board[itrRow][itrCol] == 'Q') return false;
//         ++itrRow, --itrCol;
//     }

//     return true;
// }

// void f(int col, int n, vector<string>& board, vector<vector<string>>& ds) {
//     if(col == n) {
//         ds.push_back(board);
//         return ;
//     }

//     for (int row = 0; row < n; row++)
//     {
//         if(isSafe(row, col, n, board)) {
//             board[row][col] = 'Q';
//             f(col+1, n, board, ds);
//             board[row][col] = '.';
//         }
//     }
// }


// Approach 2 --> Optimized Backtracking

void f(int col, int n, vector<string>& board, vector<bool>& leftRow, vector<bool>& upperLeftDiagonal, vector<bool>& lowerRightDiagonal, vector<vector<string>>& ds) {
    if(col == n) {
        ds.push_back(board);
        return ;
    }

    for (int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 and upperLeftDiagonal[(n-1)+(col-row)] == 0 and lowerRightDiagonal[row+col] == 0) {
            leftRow[row] = 1, upperLeftDiagonal[(n-1)+(col-row)] = 1, lowerRightDiagonal[row+col] = 1;
            board[row][col] = 'Q';
            f(col+1, n, board, leftRow, upperLeftDiagonal, lowerRightDiagonal, ds);
            leftRow[row] = 0, upperLeftDiagonal[(n-1)+(col-row)] = 0, lowerRightDiagonal[row+col] = 0;
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 5;
    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;
    // Approach 1 --> Simple Backtracking
    // f(0, n, board, ans);

    vector<bool> uld(2*n-1, 0), lrd(2*n-1, 0), lr(n, 0);
    // Approach 2 --> Optimized Backtracking
    f(0, n, board, lr, uld, lrd, ans);

    cout<<ans.size()<<endl;
    cout<<"[ ";
    for (auto &&i : ans)
    {
        cout<<"[ ";
        for (auto &&j : i)
        {
            cout<<"\""<<j<<"\" ";
        }
        cout<<"] ";
    }
    cout<<"]";
    return 0;
}