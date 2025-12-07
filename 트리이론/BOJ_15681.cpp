#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> tree[100001];
int subtree_size[100001];
bool visited[100001];

int count_node(int now) {
    visited[now] = true;
    subtree_size[now] = 1;

    for(int i = 0; i < tree[now].size(); i++) {
        int next = tree[now][i];

        if(!visited[next]) {
            count_node(next);

            subtree_size[now] = subtree_size[now] + subtree_size[next];
        }
    }

    return subtree_size[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    count_node(R);

    for(int i = 0; i < Q; i++) {
        int node;
        cin >> node;

        cout << subtree_size[node] << "\n";
    }
    
    return 0;
}