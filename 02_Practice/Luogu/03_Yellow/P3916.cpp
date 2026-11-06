#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector < int > v[MAXN];
int a[MAXN],n,m;
bool isRead[MAXN];

void insert(int from,int to){
	v[from].push_back(to);
}

void dfs(int nowp,int nowans){
	if(!isRead[nowp]){
		a[nowp] = nowans;
		isRead[nowp] = 1;
		for(int i = 0; i < v[nowp].size(); i++){
			dfs(v[nowp][i],nowans);	
		}
	}
}

int main(){
	cin>>n>>m;
	int nowu,nowv;
	for(int i = 1; i <= m; i++){
		cin>>nowu>>nowv;
		insert(nowv,nowu);
	}
	for(int i = n; i >= 1; i--){
		dfs(i,i);
	}
	for(int i = 1; i <= n; i++){
		cout<<a[i]<<' ';
	}
	return 0;
}