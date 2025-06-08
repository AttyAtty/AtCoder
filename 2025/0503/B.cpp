#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> rotate(vector<vector<char>> S, int N) {
    vector<vector<char>> tmp(N,vector<char>(N, '.'));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[j][N-1-i] = S[i][j];
        }
    }
    return tmp;
}

int main() {
    int N;
    cin >> N;
    vector<int> count = {0,1,2,3};
    vector<vector<char>> S(N,vector<char>(N, '.'));
    vector<vector<char>> T(N,vector<char>(N, '.'));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> S[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> T[i][j];
        }
    }

    for(int k = 0; k < 4; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(S[i][j] != T[i][j]){
                    count[k]++;
                };
            }
        }
        S = rotate(S,N);
    }

    int min = count[0];
    for(int i = 1; i<4; i++){
        if(min > count[i]){
            min = count[i];
        }
    }
    
    cout << min << endl;
}

///////////////////////////////////////
// 解答例 (c++)

// #include<bits/stdc++.h>
// using namespace std;

// int count_diff(vector<string>S, vector<string>T){
// 	int N = S.size();
// 	int ans = 0;
// 	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(S[i][j]!=T[i][j])ans++;
// 	return ans;
// }

// vector<string> right_rot90(vector<string>S){
// 	int N = S.size();
// 	vector<string>ret(N, string(N,'.'));
// 	for(int i=0;i<N;i++)for(int j=0;j<N;j++)ret[i][j]=S[N-1-j][i];
// 	return ret;
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	vector<string> s(n), t(n);
// 	for(auto &x:s)cin >> x;
// 	for(auto &x:t)cin >> x;
	
// 	int ans = 1e9;   //めちゃくちゃデカい数．
// 	for(int rot_count=0;rot_count<4;rot_count++){
// 		ans = min(ans, count_diff(s,t)+rot_count);
// 		s = right_rot90(s);
// 	}
// 	cout << ans << endl;
// }


//////////////////////////////////////////////////////////
// 解答例 (Python)

// N = int(input())
// S = [input() for _ in range(N)]
// T = [input() for _ in range(N)]

// def right_rot90(S):
//   return list(zip(*S[::-1]))

// def count_diff(S,T):
//   return sum([1 for si,ti in zip(S,T) for sij,tij in zip(si,ti) if sij!=tij])

// ans = 10**9
// for rot_count in range(4):
//   ans = min(ans, count_diff(S,T)+rot_count)
//   S = right_rot90(S)

// print(ans)
