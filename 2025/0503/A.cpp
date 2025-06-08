#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> arr(26, false);

    for(int i = 0; i < 26; i++){
        if(S[i] == '\0'){
            break;
        }
        int alphabet = static_cast<int>(S[i]);
        arr[alphabet - 97] = true;
        // 97なaのASCIIコード
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] == false){
            cout << static_cast<char>(i+97) << endl;
            break;
        }
    }
}

//////////////////////////////////////////////////////////////
//解答例1   a, b, … z を順に仮定して、それがS に含まれているか判定
// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string s;
//   cin >> s;
//   for(char c='a';c<='z';c++){
//     bool ok=true;
//     for(int i=0;i<s.size();i++){
//       if(s[i]==c){ok=false;}
//     }
//     if(ok){
//       cout << c << "\n";
//       return 0;
//     }
//   }
//   return 0;
// }

////////////////////////////////////////////////////////////////
//解答例2 バケットソートを利用する

// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string s;
//   cin >> s;
//   vector<int> bucket(26,0);
//   for(auto &nx : s){
//     bucket[nx-'a']=1;
//   }
//   for(char c='a';c<='z';c++){
//     if(bucket[c-'a']==0){
//       cout << c << "\n";
//       return 0;
//     }
//   }
//   return 0;
// }



////////////////////////////////////////////////////////////////
//解答例3 ある要素の存在を判定できる関数を使う

// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string s;
//   cin >> s;
//   for(char c='a';c<='z';c++){
//     if(s.find(c)==std::string::npos){
//       cout << c << "\n";
//       return 0;
//     }
//   }
//   return 0;
// }


////////////////////////////////////////////////////////////////
//解答例4 ソートして比較する

// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string s;
//   cin >> s;
//   sort(s.begin(),s.end());
//   s.push_back('*');
//   string l="abcdefghijklmnopqrstuvwxyz";
//   int p=0;
//   for(int i=0;;i++){
//     if(s[p]!=l[i]){
//       cout << l[i] << "\n";
//       return 0;
//     }
//     while(s[p]==l[i]){
//       p++;
//     }
//   }
//   return 0;
// }

///////////////////////////////////////////////////////////
//解答例5 abcdefghijklmnopqrstuvwxyz を後ろに付けてソートする

// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string s;
//   cin >> s;
//   string l="abcdefghijklmnopqrstuvwxyz";
//   for(auto &nx : l){
//     s.push_back(nx);
//   }
//   sort(s.begin(),s.end());
//   s="*"+s+"*";
//   for(int i=1;;i++){
//     if(s[i-1]!=s[i] && s[i]!=s[i+1]){
//       cout << s[i] << "\n";
//       return 0;
//     }
//   }
//   return 0;
// }
