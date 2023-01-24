// * My Approach

// #include<bits/stdc++.h>
// using namespace std;

// bool f(vector<vector<char>>& board, vector<vector<bool>>& rowStatus, vector<vector<bool>>& columnStatus, vector<vector<bool>>& gridStatus) {
//     for(int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++)
//         {
//             if(board[i][j] == '.'){
//                 for(int val = 0; val < 9; val++) {
//                     if(rowStatus[i][val]==0 and columnStatus[j][val]==0 and gridStatus[((i/3)*3)+(j/3)][val]==0){
//                         board[i][j] = (val+49);
//                         rowStatus[i][val] = 1;
//                         columnStatus[j][val] = 1;
//                         gridStatus[((i/3)*3)+(j/3)][val] = 1;
//                         if(f(board, rowStatus, columnStatus, gridStatus)){
//                             return true;
//                         }
//                         board[i][j] = '.';
//                         rowStatus[i][val] = 0;
//                         columnStatus[j][val] = 0;
//                         gridStatus[((i/3)*3)+(j/3)][val] = 0;
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main(){
//     vector<bool> r(9, 0), c(9, 0), g(9, 0);
//     vector<vector<bool>> rS(9, r), cS(9, c), gS(9, g);
//     vector<vector<char>> b = {
//         {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
//         {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
//         {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
//         {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
//         {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
//         {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
//         {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
//         {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
//         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//     };

//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if(b[i][j] != '.') {
//                 rS[i][b[i][j]-49] = 1;
//                 cS[j][b[i][j]-49] = 1;
//                 gS[((i/3)*3)+(j/3)][b[i][j]-49] = 1;
//             }
//         }
//     }

//     for (auto &&i : b)
//     {
//         for (auto &&j : i)
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;

//     f(b, rS, cS, gS);

//     for (auto &&i : b)
//     {
//         for (auto &&j : i)
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
    
//     return 0;
// }

// * Striver's Approach

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++)
    {
        // Row Check
        if(board[row][i] == c) return false;

        // Column Check
        if(board[i][col] == c) return false;

        // 3*3 Grid Check
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c) return false;
    }
    return true;
}

bool f(vector<vector<char>>& board){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++)
                {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(f(board)){
                            return true;    
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> b = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    for (auto &&i : b)
    {
        for (auto &&j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    f(b);

    for (auto &&i : b)
    {
        for (auto &&j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}