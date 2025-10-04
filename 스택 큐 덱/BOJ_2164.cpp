#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> q;

    int n ,x;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    while( q.size() > 1) {

        q.pop();

        x = q.front();
        q.push(x);
        q.pop();

    }

    cout << q.front();

    return 0;

}