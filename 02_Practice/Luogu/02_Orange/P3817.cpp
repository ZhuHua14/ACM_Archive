// P3817 小 A 的糖果
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll a[MAXN],ans,x,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	ll dx;
	for(int i = 2; i <= n; i++){
		dx = a[i] + a[i - 1] - x;
		if(dx <= 0) dx = 0;
		else if(a[i] >= dx) a[i] -= dx;
		else{
			a[i] = 0;
			dx -= a[i];
			a[i - 1] -= a[i];
		}
		ans += dx;
	}
	cout << ans << endl;
	return 0;
}
