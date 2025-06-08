#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<string>> map(h, vector<string>(w));
    
    for(int i = 0; i< h; i++){
        for(int j = 0; j< h; j++){
            cin >> map[i][j];
        }
    }


}

///////////////////////////////////////////
//幅優先探索

// #include <iostream>
// #include <queue>
// #include <string>
// using namespace std;

// int main() {
//   int H, W;
//   cin >> H >> W;
//   vector<string> S(H);
//   for (auto& s : S) cin >> s;

//   queue<pair<int, int>> Q;

    //Eの位置を覚える
//   for (int i = 0; i < H; i++) {
//     for (int j = 0; j < W; j++) {
//       if (S[i][j] == 'E') Q.emplace(i, j);
//     }
//   }

    //探索するときの移動のベクトル
//   int dx[] = {1, 0, -1, 0};
//   int dy[] = {0, 1, 0, -1};

    //ラムダ式を使って関数名省略
    //i,jがグリッド内に入っていないかどうかを見ている．
//   auto ok = [&](int i, int j) { return 0 <= i and i < H and 0 <= j and j < W; };
//   string A = "^<v>";
//   while (!Q.empty()) {
//     auto [i, j] = Q.front();
//     Q.pop();
//     for (int k = 0; k < 4; k++) {
//       int ni = i + dx[k];
//       int nj = j + dy[k];
//       if (!ok(ni, nj)) continue;
//       if (S[ni][nj] != '.') continue;
//       S[ni][nj] = A[k];
//       Q.emplace(ni, nj);
//     }
//   }

//   for (auto& s : S) cout << s << "\n";
// }
