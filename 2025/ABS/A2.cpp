#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int m = a*b;

    if (m%2==1) cout << "Odd" << endl;
    else cout << "Even" << endl;

    return 0;
}