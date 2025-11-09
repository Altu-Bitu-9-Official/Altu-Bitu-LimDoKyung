#include <iostream>

using namespace std;

int graph[101][101] = {0, };
bool visited[101] = {false, };
int n, m;
int infected_cmp = 0; // 감염된 컴퓨터 수

void dfs(int node){
    visited[node] = true;

    for(int i = 1; i <= n; i++){
        if(graph[node][i] == 1){
            if(!visited[i]){
                visited[i] = true;
                infected_cmp++;
                dfs(i);
            }
        }
    }
}

int main(){

    cin >> n;
    cin >> m;

    for(int i = 0; i < m; i++){
        int cmp1, cmp2; 
        cin >> cmp1 >> cmp2;

        graph[cmp1][cmp2] = graph[cmp2][cmp1] = 1;
    }

    dfs(1);

    cout << infected_cmp;

    return 0;

}