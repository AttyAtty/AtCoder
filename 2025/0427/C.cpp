#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> arr(N, vector<int>(M, false));

    for(int i = 0; i < Q; i++){
        int query, person, test;
        cin >> query >> person;
        person--;
        if(query == 1){
            cin >> test;
            test--;
            arr[person][test] = true;
        }else if(query == 2){
            for(int j = 0; j < M; j++){
                arr[person][j] = true;
            }
        }else if(query == 3){
            cin >> test;
            test--;
            if(arr[person][test]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}

////////////////////////////////////////////
//これが一番わかりやすい


// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

// 	int N,M,Q;
// 	cin>>N>>M>>Q;
// 	vector<set<int>> S(N);
// 	for(int i=0;i<Q;i++){
// 		int t;
// 		cin>>t;
// 		if(t==1){
// 			int X,Y;
// 			cin>>X>>Y;
// 			X--;
// 			if(S[X].count(-1))continue;
// 			else S[X].insert(Y);
// 		}
// 		else if(t==2){
// 			int X;
// 			cin>>X;
// 			S[X-1].clear();
// 			S[X-1].insert(-1);
// 		}
// 		else{
// 			int X,Y;
// 			cin>>X>>Y;
// 			X--;
// 			if(S[X].count(Y)||S[X].count(-1))cout<<"Yes\n";
// 			else cout<<"No\n";
// 		}
// 	}
// }

////////////////////////////////////////////
// **前者（2次元配列版）**では

// vector<vector<int>> arr(N, vector<int>(M, false));
// つまり N人 × M個のbool を最初から全部確保してます。

// だから、
// もし NもMもすごく大きいと、
// 単純に

// メモリオーバー（＝配列がでかすぎる）
// → プログラムが落ちる or RE（ランタイムエラー）

// になります。一方、**後者（set版）**は

// vector<set<int>> S(N);
// つまり、最初は空っぽの集合だけN個作るだけ。
// （テストを受けた人だけ、その都度ちょっとずつメモリを使う。）

// だから、
// NやMがバカでかくても、最初の時点では落ちない。

// 比較的わかりやすい解答例

// #include <iostream>
// #include <unordered_set>
// #include <vector>

// using namespace std;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
	
// 	int N, M, Q;
// 	cin >> N >> M >> Q;
	
// 	vector<bool> has_all(N + 1, false);
// 	vector<unordered_set<int>> specific_permission(N + 1);
	
// 	while (Q--) {
// 		int type;
// 		cin >> type;
// 		if (type == 1) {
// 			int X, Y;
// 			cin >> X >> Y;
// 			if (!has_all[X]) {
// 				specific_permission[X].insert(Y);
// 			}
// 		} else if (type == 2) {
// 			int X;
// 			cin >> X;
// 			has_all[X] = true;
// 			specific_permission[X].clear();
// 		} else if (type == 3) {
// 			int X, Y;
// 			cin >> X >> Y;
// 			if (has_all[X] || specific_permission[X].count(Y)) {
// 				cout << "Yes\n";
// 			} else {
// 				cout << "No\n";
// 			}
// 		}
// 	}
	
// 	return 0;
// }

////////////////////////////////////////////////////////////////////////
// こんな短くも書ける

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// ios::sync_with_stdio(0);cin.tie(0);
// int n,m,q;cin>>n>>m>>q;
// vector<bool> all(n+1); // all pages
// vector<unordered_set<int>> p(n+1); // some pages
// while(q--){
// int t,x,y;
// cin>>t>>x;
// if(t==1){cin>>y;p[x].insert(y);} // grant one
// else if(t==2)all[x]=1; // grant all
// else{cin>>y;cout<<(all[x]||p[x].count(y)?"Yes\n":"No\n");} // check
// }
// }