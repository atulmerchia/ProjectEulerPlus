#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef int Board [9][9];

bool solve(Board & board){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            if(board[i][j]) continue;

            bool used [10] = {true};

            for(int k = 0; k < 9; k++){
                used[board[i][k]] = true;
                used[board[k][j]] = true;
            }

            int r0 = i/3*3;
            int c0 = j/3*3;

            for(int r = 0; r < 3; r++)
                for(int c = 0; c < 3; c++)
                    if(board[r0+r][c0+c]) used[board[r0+r][c0+c]] = true;

            for(int k = 1; k < 10; k++)
                if(!used[k]){
                    board[i][j] = k;
                    if(solve(board)) return true;
                }

            board[i][j] = 0;
            return false;
        }
    return true;
}

int main() {
    Board board;
    unsigned long long raw;
    for(int i = 0; i < 9; i++){
        cin >> raw;
        for(int j = 8; j >= 0; j--){
            board[i][j] = raw % 10;
            raw /= 10;
        }
    }

    solve(board);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << endl;
    }

    return 0;
}
