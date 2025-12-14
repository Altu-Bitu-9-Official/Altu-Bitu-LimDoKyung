#include <iostream>
#include <vector>

using namespace std;

bool map[101][101] = { false };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void drawCurve(int x, int y, int d, int g) {
    vector<int> direct;
    direct.push_back(d);

    for (int i = 0; i < g; i++) {
        int size = direct.size();
        for (int j = size - 1; j >= 0; j--) {
            int next_direct = (direct[j] + 1) % 4;
            direct.push_back(next_direct);
        }
    }

    map[y][x] = true;
    for (int dir : direct) {
        x += dx[dir];
        y += dy[dir];
        map[y][x] = true;
    }
}



int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        drawCurve(x, y, d, g);
    }        
    
    int result = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}