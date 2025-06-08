#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i=0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i < n; i++) {
        v.erase(unique(v.begin(), v.end()), v.end());
        // uniqueは連続する重複を削除するので、ソート後に使用
        // eraseは削除されてゴミが入った要素を削除するために使用．ここで配列のサイズが小さくなる
    }
    cout << v.size() << endl;
    return 0;
}