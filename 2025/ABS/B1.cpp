#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    int count = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(true){
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                cout << count << endl;
                return 0;
            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] /= 2;
        }
        count++;
    }
}