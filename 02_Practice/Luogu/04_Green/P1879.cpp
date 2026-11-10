// P1879 [USACO06NOV] Corn Fields G
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 15;
const int MAXM = 12;
const int MAXS = 150;
const int MOD = 1e8;

ll m,n,c[MAXN],f[MAXN][1 << MAXM];

ll lowbit(ll x){
	return x & (-x);
}
bool check1(ll k,ll pos){
	return ((k & c[pos]) == 0) && (((k << 1) & k) == 0) && (((k >> 1) & k) == 0);
}

bool check2(ll x,ll y){
	return (x & y) == 0;
}

ll popcount(ll x){
	ll ans = 0;
	while(x > 0){
		ans++;
		x -= lowbit(x);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll s = n * m;
	int nowin;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> nowin;
			c[i] <<= 1;
			if(nowin == 0) c[i]++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < (1 << m); i++){
		if(check1(i,1)){
			f[1][i] = 1;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int now = 0; now < (1 << m); now++){
			if(check1(now,i)){
				for(int pre = 0; pre < (1 << m); pre++){
					if(check1(pre,i - 1) && check2(pre,now)){
						f[i][now] = (f[i - 1][pre] % MOD + f[i][now] % MOD) % MOD;
					}
				}
			}
		}
	}
	for(int i = 0; i < (1 << m); i++){
		ans = (ans % MOD + f[n][i] % MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}
