//★2
//失敗
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++)

int main() {
    int N, C, Q, L, R;
    cin >> N;
    vector<int> c1(N, 0), c2(N, 0);
    rep(i, 0, N) {
        cin >> C;
        if(C == 1) cin >> c1[i];
        else cin >> c2[i];
    }

    // 累積和を作る．ここがこの問題の一番のポイント
    vector<int> sum1(N+1, 0), sum2(N+1, 0);
    rep(i, 0, N) {
        sum1[i+1] = sum1[i] + c1[i];
        sum2[i+1] = sum2[i] + c2[i];
    }

    cin >> Q;
    rep(i, 0, Q) {
        cin >> L >> R;
        // 区間[L, R]の合計は sum[R] - sum[L-1]
        cout << sum1[R] - sum1[L-1] << " " << sum2[R] - sum2[L-1] << endl;
    }
    return 0;
}

// 計算量を減らすための取り組みとして，累積和を用いることも結構典型的な方法だと思われる．
// これにより，区間の合計をO(1)で求めることができる．