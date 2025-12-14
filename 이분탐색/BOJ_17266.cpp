#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max_high(const vector<int>& lights, int N, int M) {

    int low = 0; //최소 높이
    int high = N; //최대 높이
    int result = N;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cover = 0; //현재까지 커버된 거리
        bool can_cover = true;

        for (int i = 0; i < M; i++) {
            
            int left = lights[i] - mid; 
            int right = lights[i] + mid; 

            if (left > cover) {
                can_cover = false; 
                break;
            }

            cover = right;
            
            if (cover >= N) {
                break;
            }
        }

        if(cover < N) {
            can_cover = false;
        }

        if (can_cover) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N;
    cin >> M;

    vector<int> lights(M);

    for (int i = 0; i < M; i++) {
        cin >> lights[i];
    }

    cout << find_max_high(lights, N, M);

    return 0;
}