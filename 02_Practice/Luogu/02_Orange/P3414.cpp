// P3414 SAC#1 - 组合数
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 6662333;

ll fp(ll k){
    ll p = 2,ans = 1;
    while(k > 0){
        if(k & 1 != 0){
            ans = ((ans % MOD) * (p % MOD)) % MOD;
        }
        p = ((p % MOD) * (p % MOD)) % MOD;
        k >>= 1;
    }
    return ans;
}


ll n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << fp(n - 1);
    return 0;
}