#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, M, X;
int map[1001][1001];
int rev_map[1001][1001];
 

vector<int> dijkstra(int start, int graph[1001][1001]) {
	vector<int> dist(N + 1, INF);
    bool visited[1001] = { false, };

	dist[start] = 0;

    for (int i = 1; i <= N; i++) {
        int min_dist = INF;
        int min_idx = -1;

        for (int j = 1; j <= N; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_idx = j;
            }
        }

        if (min_idx == -1) {// 더 이상 방문할 곳이 없는 경우
            break;
        }
        
        visited[min_idx] = true;

        // 선택된 정점을 경유지로 하여 다른 정점들에 대한 최단 거리 갱신
        for (int j = 1; j <= N; j++) {
            if (!visited[j] && graph[min_idx][j] != INF) {
                dist[j] = min(dist[j], dist[min_idx] + graph[min_idx][j]);
            }
        }
    }

	return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> M >> X;

    // 모든 길 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = INF;
            rev_map[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        
        map[u][v] = t;      // 원래 길 
        rev_map[v][u] = t;  // 뒤집은 길 
    }

    vector<int> go = dijkstra(X, map);
    vector<int> back = dijkstra(X, rev_map);

    int max_time = 0;

    for (int i = 1; i <= N; i++) {
        if (go[i] != INF && back[i] != INF) {
            int total_time = go[i] + back[i];
            if (total_time > max_time) {
                max_time = total_time;
            }
        }
    }

    cout << max_time;

    return 0;
}