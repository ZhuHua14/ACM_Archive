#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e8 + 5;
const int MAXCNT = 6e6 + 5;
ll prime[MAXCNT],cnt;
bitset<MAXN> isprime;
ll n,q;

void Eratosthenes(){
	isprime.set();
	isprime[1] = 0;
	ll tmp;
	for(int i = 2; i * i <= n; i++){
		if(isprime[i]){
			for(int j = 2; j * i <= n; j++){
				isprime[j * i] = 0;
			}
			prime[++cnt] = i;
		}
		tmp = i;
	}
	for(int i = tmp; i <= n; i++){
		if(isprime[i]){
			prime[++cnt] = i;
		}
	}
}


void Euler(){
	isprime.set();
	isprime[1] = 0;
	for(int i = 2; i <= n; i++){
		if(isprime[i]){
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++){
			isprime[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	Eratosthenes();
	ll pos;
	while(q--){
		cin >> pos;
		cout << prime[pos] << endl;
	}
	return 0;
}
