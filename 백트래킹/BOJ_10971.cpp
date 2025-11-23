#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W[10][10];
bool is_visited[10] = {false, };
int min_cost = 10000001;

void backtracking(int current_city, int visited_cnt, int current_cost){

    if(current_cost >= min_cost) { //가지치기
        return;
    }

    if(visited_cnt == N) {
        if(W[current_city][0] != 0) {

            int total_cost = current_cost + W[current_city][0];
            min_cost = min(min_cost, total_cost);
        }
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!is_visited[i] && W[current_city][i] != 0) {

            is_visited[i] = true;

            backtracking(i, visited_cnt + 1, current_cost + W[current_city][i]);

            is_visited[i] = false;
        }
    }
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    is_visited[0] = true; //0번 도시부터 시작

    backtracking(0, 1, 0);

    cout << min_cost;

    return 0;
}