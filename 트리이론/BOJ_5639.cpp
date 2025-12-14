#include <iostream>

using namespace std;

int tree[10001];

void postorder(int start, int end) {

    if(start > end) {
        return;
    }

    int root = tree[start];
    int idx = end + 1;

    for(int i = start + 1; i <= end; i++) {
        if(tree[i] > root) {
            idx = i;
            break;
        }
    }

    postorder(start + 1, idx - 1); // 왼쪽 서브트리

    postorder(idx, end); // 오른쪽 서브트리

    cout << root << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int idx = 0;
    int num;

    while(cin >> num) {
        tree[idx] = num;
        idx++;
    }

    postorder(0, idx - 1);

    return 0;
}