// P1873 [COCI 2011/2012 #5] EKO / 砍树
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 5;
int n,m,high[MAXN];
bool check(int h){
	int ansh = 0;
	for(int i = 1;i <= n;i++){
		if(high[i] > h) ansh += high[i] - h;
		//cout<<"ansh:"<<ansh<<" ";
	}
	if(ansh >= m) return 1;
	else return 0;
}
int highest = -1,ans;
signed main(){
	//freopen("P1873_3.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>high[i];
		highest = max(highest,high[i]);
	}
	int l=0,r=highest,mid;
	while(l < r){
		//cout<<l<<" "<<r<<" ";
		mid = (l + r) / 2;
		//cout<<(int)(check(mid))<<endl;;
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