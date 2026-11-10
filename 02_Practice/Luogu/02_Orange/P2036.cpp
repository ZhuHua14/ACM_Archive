// P2036 [COCI 2008/2009 #2] PERKET
#include<bits/stdc++.h>
const int INF = 2e9;
using namespace std;
int n,ans=INF,absnow;
struct node{
	int sour,ku;
}; 
node llist[15];
void dfs(int nowsour,int nowku,int nowp){
	if(nowp > n){	
		if(nowsour == 1 && nowku == 0) return;
		ans = min(abs(nowsour - nowku),ans);
		return;
	}

	dfs(nowsour,nowku,nowp + 1);
	dfs(nowsour * llist[nowp].sour,nowku + llist[nowp].ku,nowp + 1);
} 
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>llist[i].sour>>llist[i].ku;
	}
	dfs(1,0,1);
	cout<<ans;
	return 0;
} 