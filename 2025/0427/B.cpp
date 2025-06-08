#include <bits/stdc++.h>
using namespace std;

int main() {
    string t, u;
    cin >> t;
    int numt = t.length();
    vector<char> T(numt);
    cin >> u;
    int numu = u.length();
    vector<char> U(numu);

    for (int i = 0; i < numt; i++) {
        T[i] = t[i];
    }
    for (int i = 0; i < numu; i++) {
        U[i] = u[i];
    }

    for (int i = 0; i <= numt - numu; i++) {
        bool match = true;
        for (int j = 0; j < numu; j++) {
            if (T[i + j] != '?' && T[i + j] != U[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}


///////////////////////////////////////////
//以下が一位の例．文字列をいちいち配列に入れなくてもよかった．
// 文字列が既にcharの配列みたいなもの．そのままインデックスで何文字目かとかを指定できる．


// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string T, U;
//     cin >> T >> U;
    
//     int lenT = T.length();
//     int lenU = U.length();
    
//     // Try to match U as a contiguous substring of T
//     for (int i = 0; i <= lenT - lenU; i++) {
//         bool match = true;
        
//         // Check if U can match the substring of T starting at index i
//         for (int j = 0; j < lenU; j++) {
//             if (T[i + j] != '?' && T[i + j] != U[j]) {
//                 match = false;
//                 break;
//             }
//         }
        
//         if (match) {
//             cout << "Yes" << endl;
//             return 0;
//         }
//     }
    
//     cout << "No" << endl;
//     return 0;
// }
