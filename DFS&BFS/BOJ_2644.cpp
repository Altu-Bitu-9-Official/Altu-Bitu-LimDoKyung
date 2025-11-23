#include <iostream>

using namespace std;

int graph[101][101] = {0, };
bool visited[101] = {false, };
int n, p1, p2, m;

void dfs(int node, int family_rel = 0){
    visited[node] = true;

    if(node == p2){
        cout << family_rel;
        exit(0);
    }

    for(int i = 1; i <= n; i++){
        if(graph[node][i] == 1 || graph[i][node] == 1){
            if(!visited[i]){
                visited[i] = true;
                dfs(i, family_rel + 1);
            }
        }
    }
}


int main(){

    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        graph[x][y] = graph[y][x] = 1;
    }

    dfs(p1, 0);

    cout << -1; // 관계가 없는 경우

    return 0;

}