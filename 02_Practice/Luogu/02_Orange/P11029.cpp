// P11029 『DABOI Round 1』A Simple Problem
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 998244353;

ll f,g,h;
ll fpow(ll n,ll m){
	if(m == 0) return 1;
	if(m == 1) return n;
	ll t = fpow(n,m / 2) % MOD;
	if(m % 2 == 0) return ((t % MOD) * (t % MOD)) % MOD;
	else return ((((t % MOD) * (t % MOD)) % MOD) * (n % MOD)) % MOD;
}

ll n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	f = 1; g = 1,h = 1;
	for(int i = 2; i <= n; i++){
		g = (g % MOD) * (fpow(i,i) % MOD);
		h = (h % MOD) * (g % MOD) % MOD;
		f = (f % MOD) * (h % MOD);
	}
	cout << f % MOD << endl;
	return 0;
}