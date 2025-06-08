#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main (){
    int n, s;
    cin >> n >> s;
    int t, past=0, time=0;
    while(n > 0){
        cin >> t;
        time = past;
        past = t;
        if (past-time >= s+ 0.5){
            cout << "No" << endl;
            return 0;
        }
        n -= 1;
    }
    cout << "Yes" << endl;
    return 0;
}