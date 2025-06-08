#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    string s;
    int count =0;

    cin >> s;
    for(char c : s){
        if(c=='1')count++;
    }
    cout << count << endl;
    return 0;
}