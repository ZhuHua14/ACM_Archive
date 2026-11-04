#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fast_pow(ll a,ll b,ll p){
	ll ans = 1,tmp = a;
	while(b){
		if(b & 1){
			ans = ((ans % p) * (tmp % p)) % p;  
		}
		tmp = ((tmp % p) * (tmp % p)) % p;
		b >>= 1; 
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a,b,p;
	cin >> a >> b >> p;
	cout << a << '^' << b << " mod " << p << '=' << fast_pow(a,b,p);	
	return 0;
}