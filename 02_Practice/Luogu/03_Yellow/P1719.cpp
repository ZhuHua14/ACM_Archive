// P1719 最大加权矩形
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 125;
ll n,a[MAXN][MAXN],sum[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	ll ans = -0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int x = i; x <= n; x++){
				for(int y = j; y <= n; y++){
					ans = max(ans,sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
