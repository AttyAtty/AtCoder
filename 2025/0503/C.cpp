#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    if(N != M){
        cout << "No" << endl;
        return 0;
    }

    vector<int> count(N, 0);

    int j;

    for(int i = 0; i < 2*M; i++){
        cin >> j;
        count[j-1]++;
    }

    for(int i = 0; i < N; i++){
        if(count[i] != 2){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}

//  こっちだとWA
// サイクルグラフが二つあった場合に，Yesになってしまう．
//すべてが人つなぎになっているかどうかの判定を加えたい
//それも可能にしたのがC2

// DFS/BFS/Union-Find という手法を使う