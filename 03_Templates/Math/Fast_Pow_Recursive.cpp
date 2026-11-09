#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,p;
ll ans;
ll fastpow(ll a,ll b,const ll p){
    if(b == 1) return a;
    if(b == 0) return 1;
    ll res = fastpow(a,b / 2ll,p);
    if((b & 1) == 0) return ((res % p) * (res % p)) % p;
    else return ((((res % p) * (res % p)) % p) * (a % p)) % p;
}

int main(){
    cin >> a >> b >> p;
    printf("%lld^%lld p %lld=%lld",a,b,p,fastpow(a,b,p));
    return 0;
}