//★２
//△おしい
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++)

int main () {
    //mainの中で書かなければいけない
    ios::sync_with_stdio(false); // C の入出力との同期を切って cin/cout を高速化
    cin.tie(nullptr);            // cin から cout への自動フラッシュを無効にしてさらに高速化
   
    int h,w;
    cin >> h >> w;

    if(h==1 || w==1) {
        cout << h * w << endl; // 高さまたは幅が1のときは全マスに置いてもOK
        return 0;
    }
    // 高さと幅が両方とも2以上のときは、2×2の正方形に2個以上置かない条件を満たすために、
    // 高さと幅をそれぞれ半分にして、置けるマスの数を計算する
    if(h%2==1) h = h/2 + 1;
    else h = h/2;

    if(w%2==1) w = w/2 + 1;
    else w = w/2;

    cout << h*w << endl;
    return 0;
}

//この(h==1 || w==1)トラップ．コーナーケースの処理をうまくできるかどうかがポイント
// つまり、**隣接を避ける条件が「2×2の正方形に2個以上置かない」**というものなら、
// 高さまたは幅が1のときは、その条件を気にせず全マスに置いてもOKです。