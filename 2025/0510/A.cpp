#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int r, x;
    cin >> r >> x;
    if(x == 1){
        if(r >= 1600 && r <= 2999){
            cout << "Yes" << endl;
            return 0;
        }
    }else if(x == 2){
        if(r >= 1200 && r <= 2399){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}