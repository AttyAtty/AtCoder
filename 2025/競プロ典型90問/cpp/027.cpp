//★２
//△高速化ができなかった
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++)
//defineの後ろには;はつけない

int main() {
    ios::sync_with_stdio(false); // C の入出力との同期を切って cin/cout を高速化
    cin.tie(nullptr);            // cin から cout への自動フラッシュを無効にしてさらに高速化

    int N;
    cin >> N;
    unordered_set<string> seen;  //unordered_setは重複なしに要素を管理できる箱のようなもの．内部ではハッシュテーブルを使っている
                                //要素の追加(insert)と要素の検索(find)がO（1）でできる
    seen.reserve(N);               // 事前にメモリ確保しておくとさらに高速
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        // insert の返り値.second が true なら初登場
        if(seen.insert(t).second){//二重ループだとO(n^2)だったところをO(n)くらいにまでできた
            cout << i+1 << endl;
        }
    }
    return 0;
}