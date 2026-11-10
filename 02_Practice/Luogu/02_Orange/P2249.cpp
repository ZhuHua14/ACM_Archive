// P2249 【深基13.例1】查找
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int n,m,a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int q,pos;
	while(m--){
		cin >> q;
		pos = lower_bound(a + 1,a + 1 + n,q) - a;
		cout << (a[pos] == q ? pos:-1) << ' ';
	}
	return 0;
}
