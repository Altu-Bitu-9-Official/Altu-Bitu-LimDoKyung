#include <iostream>

using namespace std;

int board[20][20];

//기로, 세로, 대각선 밑으로, 위로
int x[4] = {0, 1, 1, -1};
int y[4] = {1, 0, 1, 1};

bool is_onBoard(int row, int col){
    return (row >= 1 && row <= 19 && col >= 1 && col <= 19);
}

bool check(int row, int col, int stone){

    for(int dir = 0; dir < 4; dir++){
        int count = 1;

        for(int step = 1; step < 5; step++){
            int nr = row + x[dir] * step;
            int nc = col + y[dir] * step;

            if(is_onBoard(nr, nc) && board[nr][nc] == stone){
                count++;
            }
            else{
                break;
            }
        }

        if(count == 5){

            int nr_sixth = row + x[dir] * 5;
            int nc_sixth = col + y[dir] * 5;

            //육목 확인
            if(is_onBoard(nr_sixth, nc_sixth) && board[nr_sixth][nc_sixth] == stone){
                continue;
            }
            int nr_prev = row - x[dir];
            int nc_prev = col - y[dir];

            //육목 확인
            if(is_onBoard(nr_prev, nc_prev) && board[nr_prev][nc_prev] == stone){
                continue;
            }

            return true;
        }
    }

    return false;
}


int main(){

    for(int  i = 1; i <= 19; i++){
        for(int j = 1; j <= 19; j++){
            cin >> board[i][j];
        }
    }

    for(int col = 1; col <= 19; col++){
        for(int row = 1; row <= 19; row++){
            if(board[row][col] == 1 || board[row][col] == 2){ //바둑돌이 있으면
                if(check(row, col, board[row][col])){

                    cout << board[row][col] << "\n"; //승자
                    cout << row << " " << col; //좌표

                    return 0;
                }
            }
        }
    }

    cout << 0; //승자가 없을 때

    return 0;
}