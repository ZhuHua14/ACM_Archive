// P4933 大师
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXH = 4e4 + 5;
const int DELTA = 2e4;
const int MOD = 998244353;

int n,h[MAXN],f[MAXN][MAXH];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans++;
        for(int j = 1; j < i; j++){
            f[i][h[j] - h[i] + DELTA] += (f[j][h[j] - h[i] + DELTA] % MOD) + 1;
            f[i][h[j] - h[i] + DELTA] %= MOD;
            ans = ((ans % MOD) + (f[j][h[j] - h[i] + DELTA] % MOD) + 1) % MOD;
        }
    }
    cout << ans;
    return 0;
}