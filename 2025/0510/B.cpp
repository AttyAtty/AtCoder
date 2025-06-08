#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m, scan, top=0, kaisu=0;
    cin >> n >> m;
    vector<int> count(m,0);
    stack<int> array;

    for(int i = 0; i<n; i++){
        cin >> scan;
        count[scan-1]++;
        array.push(scan);
    }


    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(count[j] == 0){
                cout << kaisu << endl;
                return 0;
            }
        }
        top = array.top();
        count[top-1]--;
        array.pop();
        kaisu++;
    }

    cout << kaisu << endl;
    return 0;
}

//////////////////////////////////////////////
// 解答例
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         --a[i];
//     }

//     int ans = 0;
//     while (true) {
//         vector<bool> exist(m);
//         for (int i: a) exist[i] = true;
//         bool ok = false;
//         for (bool b: exist) {
//             if (!b) ok = true;
//         }
//         if (ok) break;
//         ++ans;
//         a.pop_back();
//     }

//     cout << ans << endl;
// }

