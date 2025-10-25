#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    int cnt = 0;

    cin >> n >> k;

    vector<char> arr(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {

        if(arr[i] == 'H'){
            continue;
        }

        if(arr[i] == 'P'){

            int start = max(0, i - k);
            int end = min(n - 1, i + k);

            for(int j = start; j <= end; j++) {
                if(arr[j] == 'H') {
                    cnt++;
                    arr[j]--;
                    break;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}