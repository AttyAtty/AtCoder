#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n,0);

    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for (int i = 0; i < q; ++i){
        int l,r,x, sum=0, count=0;// ｂに残った文字数
        cin >> l >> r >> x;
        vector<int> b(r-l+1,0); //とってきたやつ
        vector<int> number(n,0); //重複があるか見るよう

        for(int j = l-1; j < r; ++j){
            if(arr[j]<x){
                b[count] = arr[j];
                number[arr[j]-1]++;
                count++;
            }
        }
        
        int pattern = 1; //順列．総数

        for(int j = count; j >0; --j){
            pattern*= j;
        }

        for(int j = 0; j < n; ++j){
            if(number[j]>=2){
                int k = number[j];
                while(number[j]>1){
                    k *= number[j];
                    number[j]--;
                }
                pattern /= k;
            }
        }
        cout << pattern << endl;
    }
    return 0;
}
