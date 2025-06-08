#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

#define rep(i,a,b) for(int i=(a); i<(b); i++) //書きやすさのためによく使うマクロ定義
typedef longlong ll;
//最小値の最大化には二分探索を使うのが典型らしい
int main() {
    ll N,L,K;

    vector<ll> A;
    cin >> N >> L >> K;
    A.resize(N);//配列のサイズをNに設定
    rep(i, 0, N) {
        cin >> A[i];
    }
}

// ムズイ．ある程度実力をつけてから帰ってくる
https://drken1215.hatenablog.com/entry/2021/06/12/020300