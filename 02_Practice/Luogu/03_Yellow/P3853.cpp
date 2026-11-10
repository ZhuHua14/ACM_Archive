// P3853 [TJOI2007] 路标设置
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n,l,k,a[MAXN],maxlen,ans;
bool check(int len){
	int nowcnt = k,nowneed;
	for(int i = 1;i <= n;i++){
		if(a[i + 1] - a[i] > len){
			if((a[i + 1] - a[i]) % len != 0) nowneed = (a[i + 1] - a[i]) / len;
			else nowneed = (a[i + 1] - a[i]) / len - 1;
			nowcnt -= nowneed;
		}
	}
	if(nowcnt >= 0) return 1;
	return 0;
}
int main(){
	cin>>l>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	/*for(int i = 1;i < n;i++){
		len[i] = a[i+1] - a[i];
		maxlen = max(maxlen,len[i]);
	}*/
	int left = 1,right = l,mid;
	while(left < right){
		mid = (left + right) / 2;
		if(check(mid)){
			ans = mid;
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	cout<<ans;
	return 0;
}