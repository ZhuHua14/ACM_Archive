// P1182 数列分段 Section II
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 9;
int n,m,a[MAXN];
bool check(int x){
	int nowcnt = 1,nowsum = 0;
	for(int i = 1;i <= n;i++){
		if(nowsum + a[i] > x){
			nowcnt++;
			nowsum = 0;
		}
		nowsum += a[i];
	}
	return nowcnt <= m; 
}
signed main(){
	cin>>n>>m;
	int maxl = 0,maxr = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		maxl = max(maxl,a[i]);
		maxr += a[i];
	}
	int l = maxl,r = maxr,ans = 0,mid;
	while(l < r){
		//cout<<ans<<" "<<l<<' '<<r<<" "; 
		mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<ans;
	return 0;
}