#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 100000;

vector<long long> fact(MAX + 1), inv_fact(MAX + 1);

// 二分累乗法
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 階乗 & 逆元事前計算
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX] = modpow(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

int main() {
    precompute();

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    map<int, vector<int>> pos; // 値ごとの出現位置

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r; // 0-indexed

        int total = 0;
        map<int, int> freq;

        for (auto &[val, indices] : pos) {
            if (val >= x) break;
            // indices の中で [l, r] にある数をカウント
            int cnt = upper_bound(indices.begin(), indices.end(), r) - 
                      lower_bound(indices.begin(), indices.end(), l);
            if (cnt > 0) {
                freq[val] = cnt;
                total += cnt;
            }
        }

        // 重複順列数の計算: total! / (f1! * f2! ...)
        long long res = fact[total];
        for (auto &[_, f] : freq) {
            res = res * inv_fact[f] % MOD;
        }

        cout << res << '\n';
    }

    return 0;
}
