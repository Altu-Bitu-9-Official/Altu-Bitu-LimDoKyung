#include <iostream>
#include <vector>


using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void isPrime() {

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= MAX; i++) {
        if(is_prime[i]){
            for(int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void conjecture(int n) {

    for(int a = 3; a <= n/2; a +=2){

        int b = n - a;

        if(is_prime[a] && is_prime[b]){
            cout << n << " = " << a << " + " << b <<"\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    isPrime();

    while(true){

        cin >> n;

        if( n == 0 ) {
            break;
        } else {
            conjecture(n);
        }
    }

    return 0;
}