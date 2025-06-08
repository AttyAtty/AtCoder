#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) dfs(u, graph, visited);
    }
}

int main () {
    int N, M;
    cin >> N >> M;

    if (N != M) {//頂点と辺の数は同じである必要がある．
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> graph(N);
    vector<int> count(N, 0);
    int u, v;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--; v--; // 0-index に変換
        graph[u].push_back(v);
        graph[v].push_back(u);
        count[u]++;
        count[v]++;
    }

    for (int i = 0; i < N; i++) {
        if (count[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    // 連結かどうか確認
    vector<bool> visited(N, false);
    dfs(0, graph, visited);

    // サイクルグラフが二つ以上あるときは，０(1)が含まれている方だけのサイクルグラフだけdfsで確認できる．
    // よって下のvisitedのboolを確認すると，falseとなっているのは，サイクルグラフにない点だとわかる．

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
