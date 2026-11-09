#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll a[MAXN],n,m,sum[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}	
	cin >> m;
	ll l,r;
	for(int i = 1; i <= m; i++){
		cin >> l >> r;
		cout << (sum[r] - sum[l - 1]) << endl;
	}
	return 0;
}
