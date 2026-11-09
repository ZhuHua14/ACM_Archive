#include <bits/stdc++.h>
using namespace std;
int n,k,x[25],ans;
bool f(int xx){
	for(int i = 2;i * i <= xx;i++){
		//cout << xx % i << endl;
		if(xx % i == 0) return 0;
	}
	return 1;
}
void dfs(int nowcnt,int nowsum,int nowstart){
	//cout << nowcnt << endl;
	if(nowcnt ==  k && f(nowsum)){
		ans++;
		return;
	}
	//cout<<ans<<" ";
	//cout << nowstart << endl;
	for(int i = nowstart;i <= n;i++){
		dfs(nowcnt + 1,nowsum + x[i],i + 1);
	}
	return;
} 
int main(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>x[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
} 