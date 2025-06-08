#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m,c, flag=0, back=0;
    //flag:重複があるかないかの判定
    //back:重複があった時にそのまま次の要素参照するわけではないので，どのくらい戻るかの値
    cin >> n;
    vector<int> array(n,0);

    m = n;
    for(int i=0; i<n; i++){
        // 重複なしの配列を作る
        cin >> c;
        flag = 0; //重複ない
        for(int j=0; j<array.size(); j++){
            if(array[j] == c){ //重複アリ
                flag=1;
                m -=1;
                back += 1;
                break;
            }
        }
        if(flag==0){
            //配列の要素が入っている部分の最後尾
            array.insert(array.begin()+i-back,c);
        }
    }

    //ループをせずに，配列の特定の範囲をコピーしてくる
    vector<int> result(array.begin(), array.begin() + m);
    
    // 小さい順にソート
    sort(result.begin(), result.end()); //<algorithm>ヘッダファイル

    cout << m << endl;
    for(int j=0; j<m; j++){
        cout << result[j] << " ";
    }
    cout << endl;
    return 0;
}

//#include <bits/stdc++.h> を使うとすべての標準ライブラリを含むが，非標準的で，移植性が低い