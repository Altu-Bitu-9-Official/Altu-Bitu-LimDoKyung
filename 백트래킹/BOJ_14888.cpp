#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[11];
int operations[4];
int max_result = -1000000000;
int min_result = 1000000000;

void backtracking(int idx, int current_value){

    if(idx == N) {
        max_result = max(max_result, current_value);
        min_result = min(min_result, current_value);

        return;
    }

    for(int i = 0; i < 4; i++) {

        if(operations[i] > 0) {

            operations[i]--; //연산자 사용

            switch(i) {
                case 0:
                    backtracking(idx + 1, current_value + A[idx]);
                    break;
                case 1:
                    backtracking(idx + 1, current_value - A[idx]);
                    break;
                case 2:
                    backtracking(idx + 1, current_value * A[idx]);
                    break;
                case 3:
                    backtracking(idx + 1, current_value / A[idx]);
                    break;
            }

            operations[i]++; //연산자 복구
        }
    }
}

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> operations[i];
    }

    backtracking(1, A[0]);

    cout << max_result << "\n";
    cout << min_result << "\n";

    return 0;

}