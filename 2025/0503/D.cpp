#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<int> cost(N, 0);
    vector<int> animal(M, 0);
    vector<vector<int>> whereaminalare(M, vector<int>(N,0));

    for(int i = 0; i<N; i++){
        cin >> cost[i];
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> whereaminalare[i][j];
        }
    }


}

/////////////////////////////////////////////////////////////////////////////////////////
// 同じ動物園に3度以上行く必要はありません。よって各動物園に行く回数が0,1,2 のいずれであるかを3**N通り全探索することで答えを求めることができます。
// 動物園に行く回数を決めたとき、各動物を何度見ることになるかは愚直に回数を数えることで 
// O(NM) で求めることができるため、計算量は全体でO(3**N *N*M) になります