#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

#define rep(i,a,b) for(int i=(a); i<(b); i++) //書きやすさのためによく使うマクロ定義
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int px = 0, py = 0, pt = 0; // px, pyは一つ前の座標、ptは一つ前の時間
    rep(i, 0, N) {
        int t,x,y;
        cin >> t >> x >> y;
        int dt = t - pt; // 現在の時間から前の時間を引く
        int dx = abs(x - px); // x座標の差
        int dy = abs(y - py); // y座標の差
        //int distance = dx + dy; // マンハッタン距離
        //マンハッタン距離:(2点 (x₁, y₁) と (x₂, y₂) の間の距離を「縦と横だけで移動したときの最短距離」として計算する方法)
        //数式では|x₁ - x₂| + |y₁ - y₂|で表される
        if(dt < dx + dy) {
            cout << "No" << endl;
            return 0;
        }else if(dt >= dx+dy){
            if((dt - (dx +dy)) % 2 == 0) {
                //満たすときだけ更新すればいい．ミスっていたらそもそも終わるから
                px = x; // 現在の座標を前の座標に更新
                py = y;
                pt = t; // 現在の時間を前の時間に更新
                continue;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}


////////////////////////////////////////////////
//別解

//先に配列にデータを入れておいて，順々に参照して確かめるという方法もある．やってることは同じ

// int N, T[101010], X[101010], Y[101010];
// //---------------------------------------------------------------------------------------------------
// #define yes "Yes"
// #define no "No"
// string solve() {
//     int pt = 0, px = 0, py = 0;
//     rep(i, 0, N) {
//         int d = abs(px - X[i]) + abs(py - Y[i]);
//         int dt = T[i] - pt;
//         if (dt < d) return no;
//         if ((dt - d) % 2 == 1) return no;
 
//         pt = T[i];
//         px = X[i];
//         py = Y[i];
//     }
//     return yes;
// }
// //---------------------------------------------------------------------------------------------------
// void _main() {
//     cin >> N;
//     rep(i, 0, N) cin >> T[i] >> X[i] >> Y[i];
//     cout << solve() << endl;
// }