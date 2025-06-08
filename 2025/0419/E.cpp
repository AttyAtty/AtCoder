#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20;
ll pw[2 * N];
int n, m, ans, v[N][N];
set<int> mp[N][N];
void go(int x, int y, int sum, int moves, int target, bool flag = false, int add = 1) {
    if (moves == target) {
        if (flag == true) {
            sum += v[x][y] * pw[moves] % m;
            sum %= m;
            // best to close the cycle
            auto it = mp[x][y].lower_bound(m - sum);
            if (it != mp[x][y].begin()) {
                it = prev(it);
            }
            ans = max(ans, (sum + *it) % m);
            // close the cycle
            ans = max(ans, (sum + *mp[x][y].rbegin()) % m);
        } else {
            mp[x][y].insert(sum);
        }
        return;
    }
    int idx = flag ? moves : 2 * n - moves - 2;
    int newSum = (1ll * sum + pw[idx] * v[x][y]) % m;
    // down
    if (x + add < n && x + add >= 0) {
        go(x + add, y, newSum, moves + 1, target, flag, add);
    }
    // right
    if (y + add < n && y + add >= 0) {
        go(x, y + add, newSum, moves + 1, target, flag, add);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i < 2 * N; ++i) {
        pw[i] = 10ll * pw[i - 1] % m;
    }
    if (n == 1) {
        int x;
        cin >> x;
        cout << x % m << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    int target = 2 * n - 2;
    go(0, 0, 0, 0, target / 2);
    go(n - 1, n - 1, 0, 0, (target + 1) / 2, true, -1);
    cout << ans << '\n';
    return 0;
}

// 比較的わかりやすいプログラム