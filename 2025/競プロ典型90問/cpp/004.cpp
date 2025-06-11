//★２
//成功
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++) //書きやすさのためによく使うマクロ定義

int main () {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    vector<int> h(H,0);
    vector<int> w(W,0);

    rep(i, 0, H) {
        rep(j, 0, W) {
            cin >> A[i][j];
            h[i] += A[i][j]; // 各行の合計を計算
        }
        // cout << h[i] << " ";
    }

    // cout << endl; // 行の合計を出力した後に改行

    rep(j, 0, W) {
        rep(i, 0, H) {
            w[j] += A[i][j]; // 各行の合計を計算
        }
        // cout << w[j] << " ";
    }
    // cout << endl;

    rep(i, 0, H) {
        rep(j, 0, W) {
            B[i][j] = h[i] + w[j] - A[i][j]; // 各要素から行と列の合計を引く
            cout << B[i][j];
            if (j < W - 1) cout << " "; // 行の要素間にスペースを入れる
        }
        cout << endl; // 行の終わりで改行
    }
}

//各行と各列の合計値が格納された配列を先に作成したおかげで，三重ループをせずに済んだO(n^2)にとどめられた

