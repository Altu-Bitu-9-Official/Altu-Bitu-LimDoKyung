#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> li;
vector<pair<int, int>> stack;
vector<int> visited;

void check_rotation(int current_num, int current_dir){

    if(current_num - 1 >= 0 && visited[current_num - 1] == 0){
        if(li[current_num][6] != li[current_num -1][2]){
            stack.push_back(make_pair(current_num - 1, current_dir * -1));
            visited[current_num - 1] = 1;
            check_rotation(current_num - 1, current_dir * -1);
        }
    }

    if(current_num + 1 < li.size() && visited[current_num + 1] == 0){
        if(li[current_num][2] != li[current_num + 1][6]){
            stack.push_back(make_pair(current_num + 1, current_dir * -1));
            visited[current_num + 1] = 1;
            check_rotation(current_num + 1, current_dir * -1);
        }
    }
}

int main(){

    int t, k;

    cin >> t;
    
    li.resize(t);

    for(int i = 0; i < t; i++){
        cin >> li[i];
    }

    cin >> k;

    for(int i = 0; i < k; i++){

        int num, direction;

        cin>> num >> direction;

        stack.clear();
        stack.push_back(make_pair(num - 1, direction));

        visited.assign(t, 0);
        visited[num - 1] = 1;

        check_rotation(num - 1, direction);

        while(!stack.empty()) {

            pair<int, int> top = stack.back();

            stack.pop_back();

            int tmp_num = top.first;
            int tmp_dir = top.second;

            if(tmp_dir == 1){
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else{
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0;

    for(int i = 0; i < t; i++){
        if(li[i][0] == '1'){
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}