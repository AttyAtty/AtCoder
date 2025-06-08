#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
     int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        vector<int> ones;
        for (int i = 0; i < N; ++i) {
            if (S[i] == '1') ones.push_back(i);
        }

        int minFlip = ones.size(); // 最悪、全ての '1' を消す
        int K = ones.size();

        // 探索：ones[l] から ones[r] までを残すかたまりとする
        for (int l = 0; l < K; ++l) {
            for (int r = l; r < K; ++r) {
                if (ones[r] - ones[l] == r - l) {
                    // 連続してる
                    int flip = l + (K - 1 - r); // 左にある '1' + 右にある '1'
                    minFlip = min(minFlip, flip);
                }
            }
        }

        cout << minFlip << '\n';
    }
    return 0;
}