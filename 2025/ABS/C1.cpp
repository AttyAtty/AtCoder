#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//全探索問題．スタックとかキューとかを使うってこと？
//オーバーフローを予測して，先に金額とかをlonglong型にしておくのは結構定石

typedef long long ll;
int N; ll Y;
#define rep(i,a,b) for(int i=(a); i<(b); i++) //書きやすさのためによく使うマクロ定義
// 括弧をつけるのは，複雑な式を入れたときに演算子の優先順位が変な順番にならないようにするためである．

int main() {
    cin >> N >> Y;
    // 10000円と5000円と1000円の枚数a,b,cを全探索
    rep(a,0,N+1) rep(b,0,N+1) {//ループを横に並べられる．いちいちintとか書かなくていい
        int c = N-(a+b);
        if(c >= 0){
            if(10000LL * a + 5000LL * b + 1000LL * c == Y){
                // 10000LL  5000LL 1000LL のように数値リテラルの後ろに LL を付けることで、その数値が long long 型（ll型）であることを明示している
                printf("%d %d %d\n", a,b,c);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
    
}

//////////////////////////////////////////////////////////
//別解

// #include <iostream>
// #include <algorithm> // std::max
// using namespace std;

// int div_ceil(int a, int b) {
//     return (a + b - 1) / b;
// }

// int rem_euclid(int a, int b) {
//     return ((a % b) + b) % b;
// }

// int main() {
//     int64_t a, b;
//     cin >> a >> b;
//     b /= 1000; // 単位をミリ→円に変換

//     int64_t z_min = max(5 * a - b, int64_t(0));
//     z_min = div_ceil(z_min, 4);
    
//     int64_t z = z_min + rem_euclid(b - z_min, 5);
//     int64_t x = (4 * z + b) / 5 - a;
//     int64_t y = a - x - z;

//     if (y < 0) x = y = z = -1;
//     cout << x << " " << y << " " << z << endl;
// }


// Rust関数	    C++での対応	        意味
// div_ceil(&4)	(a + b - 1) / b	    切り上げ割り算
// rem_euclid(5)	((a % b) + b) % b	ユークリッド剰余（常に非負）
// max(x, 0)	    std::max(x, 0)	    0との最大値