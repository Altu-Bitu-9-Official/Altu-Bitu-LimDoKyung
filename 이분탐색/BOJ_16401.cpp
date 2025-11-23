#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long M, N;
    long long max_size = 0;

    cin >> M >> N;

    vector<long long> snack_size(N);

    for (int i = 0; i < N; i++) {
        cin >> snack_size[i];
        max_size = max(max_size, snack_size[i]);
    }
    
    long long left = 1;
    long long right = max_size;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;

        for (int i = 0; i < N; i++) {
            total += snack_size[i] / mid;
        }

        if (total >= M) {
            result = mid;

            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result;

    return 0;
}