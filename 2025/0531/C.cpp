#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> wall(n + 1, 0);  // n+1 で r==n のときも対応

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        wall[l - 1] += 1;
        wall[r] -= 1;  // r 番目の後ろで打ち消す
    }

    // 累積和をとって、実際の壁の通過回数にする．上のところで一つずつ足していくより効率がいい
    for (int i = 1; i < n; i++) {
        wall[i] += wall[i - 1];
    }

    // 最小値を求める（n個分だけ見る）
    int result = *min_element(wall.begin(), wall.begin() + n);

    cout << result << endl;

    return 0;
}






