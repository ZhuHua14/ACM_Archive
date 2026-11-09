#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;

ll a[MAXN][MAXN],f[MAXN][MAXN],n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	ll ans = -0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 1) f[i][j] = min(min(f[i - 1][j],f[i][j - 1]),f[i - 1][j - 1]) + 1;
			ans = max(f[i][j],ans);
		}
	}
	cout << ans << endl;
	return 0;
}
