#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll ans1 = 0,sum = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans1 += 1 + min(n - i,m - j);
			sum += (n - i + 1) * (m - j + 1);
		}
	}
	cout << ans1 << ' ' << sum - ans1;
	return 0;
}
