#include<bits/stdc++.h>
#define ll long long
const int MAXN = 2e5 + 5;
using namespace std;
ll n,a[MAXN],ans,c,b;
int main(){
	cin>>n>>c;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i = 1;i <= n;i++){
		ans += upper_bound(a+1,a+n+1,a[i]-c) - lower_bound(a+1,a+n+1,a[i]-c);
	}
	cout<<ans;
	return 0;
} 