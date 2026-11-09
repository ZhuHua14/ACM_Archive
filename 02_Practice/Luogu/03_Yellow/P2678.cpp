#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
int l,n,m,way[MAXN];
bool check(int len){
	int nowcnt = m,nowp = 0;
	for(int i = 1;i <= n + 1;i++){
		if(way[i] - way[nowp] < len){
			nowcnt--;
		}
		else{
			nowp = i;
		}
	}
	if(nowcnt < 0) return 0;
	return 1;
}
int main(){
	cin>>l>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>way[i];
	}
	way[n + 1] = l;
	int left = 1,right = l,mid,ans;
	while(left <= right){
		mid = (right + left) / 2;
		if(check(mid)){
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout<<ans;
	return 0;
} 