#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[200001];
int cnt[100001];

int solution() {
    int start = 0;
    int end = 0;
    int max_len = 0;

    for(end = 0; end < N; end++) {
        cnt[arr[end]]++;

        while(cnt[arr[end]] > K) {
            cnt[arr[start]]--;
            start++;
        }

        max_len = max(max_len, end - start + 1);
    }

    return max_len;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = solution();

    cout << result;

    return 0;
}