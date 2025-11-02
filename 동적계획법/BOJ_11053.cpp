#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;

    cin >> n;

    int A[n];
    int dp[n];

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int len = 0;

    for(int i = 0; i < n; i++) {
        //기본값 자기자신
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]){

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        len = max(len, dp[i]);
    }

    cout << len;

    return 0;
}