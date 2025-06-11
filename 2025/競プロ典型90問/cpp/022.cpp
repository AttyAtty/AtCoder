//★2
//失敗．
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++);
//最大公約数を求める関数
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long A, B, C;

int main() {
	cin >> A >> B >> C;
	long long S = gcd(A, gcd(B, C));
	cout << (A / S - 1LL) + (B / S - 1LL) + (C / S - 1LL) << endl;
	return 0;
}

// なぜこのコードで「最小の切断回数」が求まるの？
// gcd(A, B, C) は「一番大きくて、A, B, C を割り切れるサイズ」。

// そのサイズで立方体に切るのが、切断数が一番少ないから。

// 各方向に (A/S - 1) 回の切断が必要なので、それを3方向分合計してる。