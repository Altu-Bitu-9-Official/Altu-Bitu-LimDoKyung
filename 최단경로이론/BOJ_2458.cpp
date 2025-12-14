#include <iostream>
#include <algorithm>

using namespace std;

bool connected[501][501];

void floyd_warshall(int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (connected[i][k] && connected[k][j]) {
                    connected[i][j] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        connected[a][b] = true; // a가 b보다 작다
    }

    floyd_warshall(N);

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue; // 자기는 제외
            }
        
            if (connected[i][j] || connected[j][i]) {
                cnt++; // i와 j 비교 가능
            }
        }

        // 나를 제외한 모든 사람(N-1)과 비교가 가능하다면 내 등수를 알 수 있음
        if (cnt == N - 1) {
            answer++;
        }
    }

    cout << answer;

    return 0;
}