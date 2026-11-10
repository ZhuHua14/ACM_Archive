// P1990 覆盖墙壁
#include <bits/stdc++.h>
const int MAXN = 1000005;
const int MOD =10000;
using namespace std;
int f[MAXN],g[MAXN],n;
int main(){
	cin>>n;
	f[0] = 1;
	f[1] = g[1] = 1;
	for(int i = 2;i <= n;i++){
		f[i] = ((f[i-1] % MOD) + (f[i-2] % MOD) + ((2 * g[i-2]) %MOD)) % MOD;
		g[i] = ((f[i-1] % MOD) + (g[i-1] % MOD)) % MOD;
	}
	cout<<f[n];
	return 0;
}