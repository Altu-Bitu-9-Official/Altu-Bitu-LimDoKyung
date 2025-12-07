#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, K, L;
int board[101][101];

vector<pair<int, char>> direction_change;

const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;

int play_game() {
    deque<pair<int, int>> snake;
    snake.push_front({1, 1});
    board[1][1] = SNAKE;

    int time = 0;
    int dir = 0; // 초기 방향 우측 (0)
    int change_index = 0;

    while(true) {
        time++;

        int head_x = snake.front().first;
        int head_y = snake.front().second;

        int nx = head_x + dx[dir];
        int ny = head_y + dy[dir];

        // 종료1 : 벽 충돌
        if(nx < 1 || nx > N || ny < 1 || ny > N) {
            break;
        }

        // 종료2 :  자기 몸 충돌
        if(board[nx][ny] == SNAKE) {
            break;
        }

        // 이동
        if(board[nx][ny] == APPLE) {
            board[nx][ny] = SNAKE;
            snake.push_front({nx, ny});
        } else {
            board[nx][ny] = SNAKE;
            snake.push_front({nx, ny});

            int tail_x = snake.back().first;
            int tail_y = snake.back().second;
            board[tail_x][tail_y] = EMPTY;
            snake.pop_back();
        }

        // 방향 전환
        if(change_index < L && time == direction_change[change_index].first) {
            if(direction_change[change_index].second == 'L') {
                dir = (dir + 3) % 4; // 완쪽
            } else {
                dir = (dir + 1) % 4; // 오른쪽
            }
            change_index++;
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> K;

    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = APPLE;
    }

    cin >> L;
    
    for(int i = 0; i < L; i++) {
        int x;
        char c;
        cin >> x >> c;
        direction_change.push_back({x, c});
    }

    int result = play_game();

    cout << result;

    return 0;
}