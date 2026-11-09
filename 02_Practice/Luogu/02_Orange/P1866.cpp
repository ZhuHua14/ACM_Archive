#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 55;
const int MOD = 1e9 + 7;

int n,m[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m[i];
    }
    sort(m + 1,m + 1 + n);
    ll tmp = 0,ans = 1;
    for(int i = 1; i <= n; i++){
        tmp = m[i] - i + 1;
        if(tmp <= 0){
            cout << 0;
            exit(0);
        }
        ans = ((ans % MOD) * (tmp % MOD)) % MOD;
    }
    cout << ans;
    return 0; 
}