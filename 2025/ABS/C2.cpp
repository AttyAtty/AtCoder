#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

//DP（Dunamic Programming）動的計画法を用いて考える問題
// 文字列 S が "dream", "dreamer", "erase", "eraser" のいずれかの文字列の連結であるかどうかを判定する
// 文字列 S の長さを n とすると、O(n) の時間で判定できる
// 分割したい文字列たち
const vector<string> strs = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;
    
    vector<bool> dp(S.size()+1, false);
    dp[0] = true;
    for (int i = 1; i <= S.size(); ++i) {
        // 4 つの文字列を順に試していく
        for (auto str: strs) {
            if (i >= str.size() &&
                dp[i - str.size()] &&
                S.substr(i - str.size(), str.size()) == str) {//配列の部分文字列を取得する．取りだしている
                dp[i] = true;
            }
        }
    }

    if (dp[S.size()]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

// 結論：「どこが動的？」
// このプログラムで動的な点は：

// 「文字列の先頭から i 文字目まで作れるか？」という状態を記録し、

// その情報をもとに、次の文字数 i + len(str) を構成可能かどうかを判断しているところ。

// つまり、「過去の結果をメモ（保存）し、それをもとに次の判断をしている」
// → これが 動的計画法（Dynamic Programming） です。

// さらに深く知りたい場合は、「最長共通部分列（LCS）」や「ナップサック問題」など他のDP問題を紹介できますよ！


//  動的計画法じゃない書き方（参考）
// もしDPを使わずにやろうとすると、全ての単語の組み合わせで全探索することになり、
// TLE（実行時間オーバー）しやすくなります。