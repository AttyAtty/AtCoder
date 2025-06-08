#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n,0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            alice += v[i];
        } else {
            bob += v[i];
        }
    }
    cout << alice - bob << endl;
    return 0;
}