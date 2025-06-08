#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (isupper(c)) cout << c;
        // if ('A' <= c && c <= 'Z') cout << c;
    }
    cout << endl;
}
