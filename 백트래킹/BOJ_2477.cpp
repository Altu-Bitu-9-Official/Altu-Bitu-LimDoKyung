#include <iostream>

using namespace std;

int main(){

    int K;
    int direction[6];
    int length[6];
    int big_area, small_area;

    cin >> K;

    for(int i = 0; i < 6; i++) {
        cin >> direction[i] >> length[i];
    }

    for(int i = 0; i < 6; i++) {
        if(direction[i % 6] == direction[(i + 2) % 6] && direction[(i + 1) % 6] == direction[(i + 3) % 6]) {

            big_area = length[(i + 4) % 6] * length[(i + 5) % 6];
            small_area = length[(i + 1) % 6] * length[(i + 2) % 6];
        }
    }

    int result = K * (big_area - small_area);

    cout << result << "\n";

    return 0;
}