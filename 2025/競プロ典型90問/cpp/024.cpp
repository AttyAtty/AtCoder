//★2
//成功
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i=(a); i<(b); i++)
//defineの後ろには;はつけない

int main () {
    int N, K, sum=0;
    cin >> N >> K;

    vector<int> A(N,0);
    vector<int> B(N,0);
    vector<int> differ(N,0);
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,N){
        cin >> B[i];
        differ[i]= abs(A[i]-B[i]);
        sum += differ[i];
    }

    if(sum <= K && (K - sum)%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}