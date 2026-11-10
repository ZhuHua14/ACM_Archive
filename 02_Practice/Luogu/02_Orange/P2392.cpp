// P2392 kkksc03 考前临时抱佛脚
#include<bits/stdc++.h>
using namespace std;
int nowans,newans,ans,nowsum,nowcnt,s[4],a[25],b[25],c[25],d[25];
void dfs(int k,int ra[]){
	if(k > nowcnt){
		nowans = max(nowans,newans);
		return;
	}
	if (newans + ra[k] <= nowsum / 2){
		newans += ra[k];
		dfs(k + 1,ra);
		newans -= ra[k];
	}
	dfs(k + 1,ra);
}
int main(){
	for(int i = 0;i < 4;i++){
		cin>>s[i];
	}
	for(int i = 1;i <= s[0];i++){
		cin>>a[i];
		a[0] += a[i];
	}
	for(int i = 1;i <= s[1];i++){
		cin>>b[i];
		b[0] += b[i];
	}
	for(int i = 1;i <= s[2];i++){
		cin>>c[i];
		c[0] += c[i];
	}
	for(int i = 1;i <= s[3];i++){
		cin>>d[i];
		d[0] += d[i];
	}
	for(int i = 0;i <= 3; i++){
		nowans = 0;
		nowcnt = s[i];
		switch(i){
			case 0: {
				nowsum = a[0];
				dfs(1,a);
				ans += nowsum - nowans;
				break;
			}
			case 1: {
				nowsum = b[0];
				dfs(1,b);
				ans += nowsum - nowans;
				break;
			}
			case 2: {
				nowsum = c[0];
				dfs(1,c);
				ans += nowsum - nowans;
				break;
			}
			case 3: {
				nowsum = d[0];
				dfs(1,d);
				ans += nowsum - nowans;
				break;
			}	
		}
		//cout<<ans<<" "<<nowans<<" "<<nowsum<<endl;
	}
	cout<<ans;
} 