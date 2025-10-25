#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x;
    // 비트마스크 변수, x가 <= 20 이므로 int(32bit)로 충분
    int S = 0;
    string operation;
    
    cin >> m;

    for(int i = 0; i < m; i++) {

        cin >> operation;

        if(operation == "add") {

            cin >>x;
            S |= (1 << x);

        }else if(operation == "remove") {
            
            cin >>x;
            S &= ~(1 << x);

        }else if(operation == "check") {

            cin >>x;

            if(S & (1 << x)){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }

        }else if(operation == "toggle") {

            cin >>x;
            S ^= (1 << x);

        }else if(operation == "all") {

            S = (1 << 21) - 1;

        }else if(operation == "empty") {

            S = 0;

        }
    }

    return 0;
}