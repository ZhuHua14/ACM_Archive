// P2415 集合求和
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 35;


ll fp(ll k){
    ll p = 2,ans = 1;
    while(k > 0){
        if(k & 1 != 0){
            ans = ans * p;
        }
        p *= p;
        k >>= 1;
    }
    return ans;
}

int a[MAXN];
ll base;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 1;
    while(cin >> a[n]){
        n++;
    };
    n--;
    base = fp(n - 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += base * a[i];
    }
    cout << ans;
    return 0;
}