#include <iostream>

using namespace std;

int main(){

    string king, stone, cmd;
    int N;

    cin >> king >> stone >> N;

    //정수 좌표로 전환
    int kCol = king[0] - 'A';
    int kRow = king[1] - '1';
    int sCol = stone[0] - 'A';
    int sRow = stone[1] - '1';

    for(int i = 0; i < N; i++) {

        cin >> cmd;

        int col = 0;
        int row = 0;

        if(cmd == "R") {
            col = 1;
        }else if(cmd == "L") {
            col = -1;
        }else if(cmd == "B") {
            row = -1;
        }else if(cmd == "T") {
            row = 1;
        }else if(cmd == "RT") {
            col = 1; row = 1;
        }else if(cmd == "LT") {
            col = -1; row = 1;
        }else if(cmd == "RB") {
            col = 1; row = -1;
        }else if(cmd == "LB") {
            col = -1; row = -1;
        }

        int next_kCol = kCol + col;
        int next_kRow = kRow + row;

        if(next_kCol < 0 || next_kCol >= 8 || next_kRow < 0 || next_kRow >= 8) {
            continue;
        }

        if(next_kCol == sCol && next_kRow == sRow) {

            int next_sCol = sCol + col;
            int next_sRow = sRow + row;

            if(next_sCol < 0 || next_sCol >= 8 || next_sRow < 0 || next_sRow >= 8) {
            continue;
            }

            sCol = next_sCol;
            sRow = next_sRow;
        }

        kCol = next_kCol;
        kRow = next_kRow;
    }

    cout << (char)('A' + kCol) << (char)('1' + kRow) << "\n";
    cout << (char)('A' + sCol) << (char)('1' + sRow) << "\n";

    return 0;
}