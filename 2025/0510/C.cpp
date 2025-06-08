#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    long long totalsum=0;
    long long squaresum =0;
    cin >> n;
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        totalsum += arr[i];
        squaresum += arr[i] * arr[i];
    }

    long long result = (totalsum * totalsum - squaresum) / 2;
    cout << result << endl;
    return 0;
}

//与えられたσの式を変形してより効率的に求められるようにしている．

//////////////////////////////////////
//解答例

// #include <bits/stdc++.h>

// using namespace std;

// using ll = long long;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     ll ans = 0, sum = 0;
//     for (int i = 0; i < n; i++) {
//         ans += sum * a[i];
//         sum += a[i];
//     }

//     cout << ans << endl;
// }
