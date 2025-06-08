#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int oddsum = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        if(i % 2 == 1){
            oddsum += t;
        }
    }
    cout << oddsum << endl;
}