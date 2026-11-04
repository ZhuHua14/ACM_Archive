#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 10;
const int MAXN = 105;

ll n,m,f[3][1 << MAXM][1 << MAXM],c[MAXN];

ll lowbit(ll x){
	return x & (-x);
}

ll popcount(ll x){
	ll ans = 0;
	while(x > 0){
		ans++;
		x -= lowbit(x);
	}
	return ans;
}

bool check1(ll l,ll pos){
	return ((l & c[pos]) == 0) && (((l << 1) & l) == 0) && (((l << 2) & l) == 0) && (((l >> 2) & l) == 0) && (((l >> 1) & l) == 0);
}

bool check2(ll x,ll y){
	return ((x & y) == 0);
}
int main(){
	freopen("out.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	cin >> n >> m;
	char nowin;
	for(int i = 1; i <= n; i++){
		for(int j = m - 1; j >= 0; j--){
			cin >> nowin;
			if(nowin == 'H'){
				c[i] += (1 << j);
			}
		}
	}
//	for(int i = 1; i <= n ; i++){
//		cout << c[i] << endl;
//	}
	for(int i = 0; i < (1 << m); i++){
		if(check1(i,1)){
			f[1][i][0] = popcount(i);
		}
	}
//	for(int i = 0; i < (1 << m); i++){
//		cerr << f[1][i][0] << ' ';
//	}
//	cerr << endl;
	for(int i = 0; i < (1 << m); i++){
		if(check1(i,2)){
			for(int j = 0; j < (1 << m); j++){
				if(check1(j,1) && check2(i,j)){
					f[2][i][j] = popcount(i) + popcount(j);
				}
			}
		}
	}
//	for(int i = 0; i < (1 << m); i++){
//		for(int j = 0; j < (1 << m); j++){
//			cerr << f[2][i][j] << ' ';
//		}
//	}
//	cerr << endl;
	for(int i = 3; i <= n; i++){
		for(int now = 0; now < (1 << m); now++){
			if(check1(now,i)){
				for(int pre = 0; pre < (1 << m); pre++){
					if(check1(pre,i - 1) && check2(now,pre)){
						for(int k = 0; k < (1 << m); k++){
							if(check1(k,i - 2) && check2(pre,k) && check2(now,k)){
								f[i % 3][now][pre] = max(f[i % 3][now][pre],f[(i - 1) % 3][pre][k] + popcount(now));	
							}
						}
					}
				}
			}
		}
//
//		for(int now = 0; now < (1 << m); now++){
//			for(int pre = 0; pre < (1 << m); pre++){
//				cerr << f[i % 3][now][pre] << ' ';
//			}
//			cerr << endl;
//		}
	}
//	for(int i=3;i<=n;i++)
//		for(int L=0;L<(1<<m);L++)
//		{
//			if(L&c[i-1] || (L&(L<<1)) || (L&(L<<2))) continue;	//特判
//			for(int S=0;S<(1<<m);S++)
//			{
//				if(S&c[i] || L&S || (S&(S<<1)) || (S&(S<<2))) continue;
//				for(int FL=0;FL<(1<<m);FL++)
//				{
//					if(FL&L || FL&S || FL&c[i-2] || (FL&(FL<<1)) || (FL&(FL<<2)))	continue;
//					f[i%3][S][L]=max(f[i%3][S][L],f[(i - 1) % 3][L][FL]+popcount(S));		//滚动数组的实现方法
//				}
//			}
//		}
	ll ans = -1;
	for(int i = 0; i < (1 << m); i++){
		for(int j = 0; j < (1 << m); j++){	
			ans = max(ans,f[n % 3][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}