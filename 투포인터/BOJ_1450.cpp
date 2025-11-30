#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long C;
long long weight[31];
vector<long long> left_group;
vector<long long> right_group;

void get_sum(int idx, int end, long long sum, vector<long long>& result) {
    if(sum > C) {
        return;
    }

    if(idx == end) {
        result.push_back(sum);
        return;
    }

    get_sum(idx + 1, end, sum, result);//현재 물건 추가 안하고 다음

    get_sum(idx + 1, end, sum + weight[idx], result);//현재 물건 추가하고 다음 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    get_sum(0, N/2, 0, left_group);

    get_sum(N/2, N, 0, right_group);

    sort(left_group.begin(), left_group.end());
    sort(right_group.begin(), right_group.end());

    int left = 0;
    int right = right_group.size() - 1;
    long long result = 0;

    while(left < left_group.size() && right >= 0) {
        long long sum = left_group[left] + right_group[right];

        if(sum <= C) {
            result += (right + 1);
            left++;
        } 
        else {
            right--; 
        }
    }

    cout << result;

    return 0;
}