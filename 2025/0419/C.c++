// ちょっとよくわからなかった

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    // 構造の準備
    vector<vector<int>> a(m);      // a[i] = 料理iの使う食材リスト
    vector<vector<int>> idx(n);    // idx[s] = 食材sが使われている料理のリスト
    vector<int> cnt(m);            // cnt[i] = 料理iに残っている苦手食材の数
    
    // 料理データの読み込み
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        cnt[i] = k;
        a[i].resize(k);
        for (auto &e : a[i]) {
            cin >> e; e--;            // 0-index に直す
            idx[e].push_back(i);      // 食材eが使われてる料理i を記録
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        b--;
        for (auto id : idx[b]) {
            cnt[id]--;
            if (cnt[id] == 0)
                ans++;
        }
        cout << ans << endl;
    }
}
