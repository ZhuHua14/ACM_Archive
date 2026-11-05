#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n,c,a[MAXN];
bool check(int len){
	int nowcnt = c - 1;
	int nowp = a[1];
	for(int i = 2;i <= n;i++){
		if(nowcnt == 0){
			return 1;
		}
		if(a[i] - nowp >= len){
			nowp = a[i];
			nowcnt--;
		}
	}
	if(nowcnt == 0){
		return 1;
	}
	return 0;
}
int main(){
	cin>>n>>c;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n);
	int l = 0,r = a[n] - a[1],mid,ans;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout<<ans;
	return 0;
} 