#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<long long> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    long long min_v = v[n - 1];

    for(int i = n - 2; i >= 0; i--){

        long long required_v = v[i];

        if(min_v % required_v == 0){
            continue;
        }

        else if(min_v % required_v != 0){

            long long k = (min_v / required_v) + 1;
            min_v = k * required_v;
        }
    }

    cout << min_v;

    return 0;

}