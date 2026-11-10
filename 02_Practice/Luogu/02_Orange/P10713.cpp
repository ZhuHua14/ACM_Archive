// P10713 【MX-X1-T1】「KDOI-05」简单的无限网格问题
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t,n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n % 2 == m % 2) cout << 3 << endl;
        else cout << 2 << endl;
    }
    return 0;
}