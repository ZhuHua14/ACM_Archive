// P1090 [NOIP 2004 提高组] 合并果子
#include<bits/stdc++.h>
using namespace std;
int n,shuru;
priority_queue <int, vector<int>, greater<int>> que;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>shuru;
		que.push(shuru);
	}
	int ans=0;
	while(que.size()!=1){
		int zancun=0;
		for(int j=0;j<2;j++){
			zancun+=que.top();
			que.pop();
		}
		ans+=zancun;
		que.push(zancun);
	}
	cout<<ans;
	return 0;
}