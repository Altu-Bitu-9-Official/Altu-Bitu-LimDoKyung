#include <iostream>
#include <algorithm>

using namespace std;

int N, d, k, c;
int dish[30001];
int cnt[30001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++) {
        cin >>dish[i];
    }

    int new_cnt = 0;

    for(int i = 0; i < k; i++) {
        if(cnt[dish[i]] == 0) {
            new_cnt++;
        }

        cnt[dish[i]]++;
    }

    int max_cnt = new_cnt;

    if(cnt[c] == 0) { // 쿠폰 초밥을 먹은 적 없다면
        max_cnt++;
    }

    //슬라이딩 윈도우 시작
    for(int i = 0; i < N; i++) {
        cnt[dish[i]]--;

        if(cnt[dish[i]] == 0) {
            new_cnt--;
        }

        int next_dish = dish[(i + k) % N];

        if(cnt[next_dish] == 0) {
            new_cnt++;
        }

        cnt[next_dish]++;

        int total = new_cnt;
        
        if(cnt[c] == 0) {
            total++;
        }

        max_cnt = max(max_cnt, total);
    }

    cout << max_cnt;

    return 0;
}