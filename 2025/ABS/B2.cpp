#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // iotaのため
using namespace std;

int main() {
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    vector<int> A(a+1), B(b+1), C(c+1);
    int count = 0;
    iota(A.begin(), A.end(), 0);// (配列の初期化で012345と入れるため)
    iota(B.begin(), B.end(), 0);
    iota(C.begin(), C.end(), 0);

    for (int a : A){
        for(int b : B){
            for(int c : C){
                if (500*a + 100*b + 50*c == x) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}