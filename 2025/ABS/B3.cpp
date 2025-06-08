#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // iotaのため
using namespace std;

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    int sum=0;
    for (int i =1; i<=n; i++){
        int sum_digits = 0;
        int num = i;
        while (num > 0) {
            sum_digits += num % 10;
            num /= 10; 
        }
        if (sum_digits >= a && sum_digits <= b) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}