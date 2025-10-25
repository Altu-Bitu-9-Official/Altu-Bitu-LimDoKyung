#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){

    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){

    int n, s, a, d;

    cin >> n >> s;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> a;
        arr[i] = abs(s - a);
    }

    if(n == 1){
        cout << arr[0];
        return 0;
    }

    d = gcd(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        d = gcd(d, arr[i]);
    }

    cout << d;

    return 0;
}

